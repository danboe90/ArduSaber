/**
 *        @file     ISR.ino
 *        @brief    This file contains all the Interrupt service routines implemented 
 *        @author   danboe90
 */




/**
 *    @brief    Function which has been set up to debounce the push-button.
 *              The pushbutton moves the state-machine from turned OFF state into 
 *              turned ON state.
 */
void pButton1ISR() {
  /* avoid button to raise other interrupts */
  detachInterrupt(digitalPinToInterrupt(pButton1));
  delay(500);                         /* debouncing */
  
  int val = digitalRead(pButton1);    /* reading again the button if still on */
  
  if(val == HIGH) {
    /* button is still pressed */
    if(PRG_STATE == 0)      { PRG_STATE = 1; }
    else if(PRG_STATE == 2) { PRG_STATE = 3; }
  }
  /* attach again the button */
  attachInterrupt(digitalPinToInterrupt(pButton1), pButton1ISR, RISING);
}




