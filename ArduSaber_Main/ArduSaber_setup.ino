/**
 *      @brief    This function is called at the beginning. It initializes the entire hardware periferals.
 *                At the end of the boot-sequence sound is played to signalize user that booting has completed.
 */
void setup() {
  Init_MPU6050();
  
  InitBlade();

  Init_SPI_Player();

  Init_DFPlayerMini();

  /* start off the serial module */
  delay(100);
  Serial.begin(9600);
  delay(100);
  
  /* ****************************** INIT PUSH-BUTTON ****************************** */
  /* declare pin 2 to bee Input with Pullup Resistor */
  pinMode(pButton1, INPUT_PULLUP);    
  /* attaching pushButton to an ISR */
  attachInterrupt(digitalPinToInterrupt(pButton1), pButton1ISR, RISING);

  /* initialize the State-Machine with the default state 0 */
  PRG_STATE = 0;

  gLastClashTime    = 0;
  gLastSwingTime    = 0;
  gMotionUpdateTime = 0;
  gLastHumTime      = 0;
  
  /* play boot sound to indicate booting has completed */
  #ifdef SPI_PLAYER
    tmrpcm.play("bootsnd.wav");
  #endif

  #ifdef DFP_PLAYER
    // gpSoundPlayer->PlayFile(1);
    gpSoundPlayer->PlaySound(eeBootSnd, 0);
    delay(9);
  #endif
  
  Serial.println("Boot finished...");
}
