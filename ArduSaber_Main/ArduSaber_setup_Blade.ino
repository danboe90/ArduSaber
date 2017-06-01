/**
 *    @file     ArduSaber_Setup_Blade.ino
 *    @author   danboe70
 *    @brief    This file contains the initialization routine for the Blade
 */




/**
 *    @brief    Initialization of the LED_PIN1 as Blade LED.
 */
void InitBlade()
{
  /* ****************************** INIT OF THE BLADE-MANAGER ****************************** */ 
  apBlade = new SingleLedBlade(LED_PIN1);
  apBlade->Init();
}

