
/**
 *      @brief    This function is in charge of the clash-sound.
 */
void isClash()
{
  /* CLASH MOMENT */
  if(apMotion->IsClash()) {
    switch(apMotion->GetClashMagnitude()) {
      case eeSmall: 
      case eeMedium: 
      case eeLarge:
        #ifdef SPI_PLAYER
          tmrpcm.play("lsabCl.wav");
        #endif
        #ifdef DFP_PLAYER
          unsigned long lClashTimeDelta;
          unsigned long lSwingTimeDelta;
          unsigned long lHumTimeDelta;
          unsigned long now;
          
          now = millis();
          lClashTimeDelta = now - gLastClashTime;
          lSwingTimeDelta = now - gLastSwingTime;
          lHumTimeDelta = now - gLastHumTime;
          
          if( lClashTimeDelta > DURATION_CLASH && lHumTimeDelta > SUPRESS_HUM && lSwingTimeDelta > SUPRESS_SWING ) {
            /* make the timestamp of the clash event */
            gLastClashTime = millis();
            // gpSoundPlayer->PlayFile(2);
            gpSoundPlayer->PlaySound( eeClashSnd, 0);
            delay(DURATION_CLASH);
            gpSoundPlayer->PlaySound(eeHumSnd, 0);
          }
        #endif
      break;
    }
  }
}


/**
 *      @biref    This function is in charge of the swing-sound
 */
void isSwing() {
  // SWING TIME 
  if(apMotion->IsSwing()) {  
    switch(apMotion->GetSwingMagnitude()) {
      case eeSmall: 
      case eeMedium: 
      case eeLarge: 
        #ifdef SPI_PLAYER
          tmrpcm.play("lsabSw.wav");
        #endif
        #ifdef DFP_PLAYER          
          unsigned long lClashTimeDelta;
          unsigned long lSwingTimeDelta;
          unsigned long lHumTimeDelta;
          unsigned long now;
    
          now = millis();
          lHumTimeDelta   = now - gLastHumTime;
          lClashTimeDelta = now - gLastClashTime;
          lSwingTimeDelta = now - gLastSwingTime;
        
          if(lSwingTimeDelta > DURATION_SWING && lHumTimeDelta > SUPRESS_HUM && lClashTimeDelta > SUPRESS_CLASH) {
            gLastSwingTime = millis();
            // gpSoundPlayer->PlayFile(7);
            gpSoundPlayer->PlaySound( eeSwingSnd, 0);
            delay(DURATION_SWING);
            // gpSoundPlayer->PlaySound(eeHumSnd, 0);
          }
        #endif                      
        break;
        
    }    
  }
}




/**
 *    @brief     This function is in charge of the hum-sound
 */
void isHum()
{
  #ifdef SPI_PLAYER
    if(!tmrpcm.isPlaying()) {
      tmrpcm.play("lsabHu.wav");
    }
  #endif
  #ifdef DFP_PLAYER
    unsigned long lClashTimeDelta;
    unsigned long lSwingTimeDelta;
    unsigned long lHumTimeDelta;
    unsigned long now;

    now = millis();
    lHumTimeDelta   = now - gLastHumTime;
    lClashTimeDelta = now - gLastClashTime;
    lSwingTimeDelta = now - gLastSwingTime;

    if(!gpSoundPlayer->IsBusy())
    {
      gpSoundPlayer->PlaySound(eeHumSnd, 0);
    }
    
    /*
    if(    lHumTimeDelta > DURATION_HUM               /* play only if last hum sound finished 
        && lClashTimeDelta > SUPRESS_CLASH            /* play only if last clash sound has been finished 
        && lSwingTimeDelta > SUPRESS_SWING )        
    {
      gLastHumTime = millis();
      // gpSoundPlayer->PlayFile(6);
      gpSoundPlayer->PlaySound(eeHumSnd, 0);
      delay(DURATION_HUM);
    }*/
  #endif
}
