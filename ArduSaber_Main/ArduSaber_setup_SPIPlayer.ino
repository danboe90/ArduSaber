
/**
 *    @brief    This function is in charge of the SPI Interface to the 
 *              SD-Card Adapter
 */
void Init_SPI_Player()
{
  /* ****************************** INIT SOUND MODULE SPI SD CARD ADAPTER ****************************** */
  #ifdef SPI_PLAYER
      pinMode(9, OUTPUT);               /* speaker output*/
      tmrpcm.speakerPin = 9;
      /* realy need the Serial config here? */
      Serial.begin(9600);
      if(!SD.begin(SD_ChipSelectPin)) {
        Serial.println("Init SD fail");
      }
      /* Set the volume to use */
      tmrpcm.setVolume(6);
  #endif
}

