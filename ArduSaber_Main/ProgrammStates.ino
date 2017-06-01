/**
 *      @file     ProgrammStates.ino
 *      @author   danboe90
 *      @brief    This file contains the four functions executed in each state of the state-machine.
 *                turnSaberOn()       - state 1, entered when pButton1 is pressed
 *                saberIsOn()         - state 2, automatically entered after leaving state 1
 *                turnSaberOff()      - state 3, entered when pButton1 is pressed again
 *                saberIsOff()        - state 0, automatically entered after leaving state 3 
 *                                      -> this state is the initial state after booting
 */




/**
 *      @brief    This function turns the saber on.
 */

void turnSaberOn() {
  /* DEBUG Output */
  // Serial.println("turnSaberOn()");
  #ifdef SPI_PLAYER
    /* play sound */
    tmrpcm.play("lsabON.wav");
  #endif
  #ifdef DFP_PLAYER
    // gpSoundPlayer->PlayFile(5);
    gpSoundPlayer->PlaySound(eePowerUpSnd, 0);
  #endif
  
  bool lPowerupComplete = false;
  while(!lPowerupComplete) {
    apBlade->SetChannel(255, 0);
    lPowerupComplete = apBlade->PowerUp(1000);
  }
  PRG_STATE = 2;
  apBlade->On();  

  
  #ifdef DFP_PLAYER
    gpSoundPlayer->PlaySound(eeHumSnd, 0);
  #endif
  
}



/**
 *      @brief    This function is executed when the saber is ON. Random Values for the glow effect are executed
 */
void saberIsOn() {
  /* apply flicker to the blade */
  apBlade->ApplyFlicker(2);

  if( (millis() - gMotionUpdateTime)>10 )
  {
    apMotion->Update();
    gMotionUpdateTime = millis();
    
    isClash();
    // isSwing();
    // isHum();    
  }
}




/**
 *      @brief    This function is executed when the saber is turning off.
 */
void turnSaberOff() {
  // Serial.println("turnSaberOff()");
  /* play sound */
  #ifdef SPI_PLAYER
    tmrpcm.play("lsabOff.wav");
  #endif
  #ifdef DFP_PLAYER
    // gpSoundPlayer->PlayFile(4);
    gpSoundPlayer->PlaySound(eePowerDownSnd, 0);
  #endif
  
  bool lPowerdownComplete = false;
  PRG_STATE = 0;

  while(!lPowerdownComplete) {
    lPowerdownComplete = apBlade->PowerDown(1000);
  }  

  

  gpSoundPlayer->Stop();
}




/**
 *      @brief    This function is executed when the saber is OFF. 
 *                No sound and no light is emitted
 */
void saberIsOff() {
  /* IDEA: execute here a blink or fade on the LED in the turn-on-Button */
}

