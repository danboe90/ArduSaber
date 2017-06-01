
/**
 *      @brief    This function initializes the DFPlayer Mini Sound Module
 *      
 *      PINNING:      
 *      nC...not COnnected
 *      
 *       ----------------------------------------------------------------------------------
 *      |   DFPlayer Mini Pin     |         Arduino Pin       |       Other Component      |
 *       ----------------------------------------------------------------------------------
 *      |         VCC             |             5V            |       nC                   |
 *      |         RX              |             nC            |       1kOhm Res            |
 *      |         TX              |             D7            |       nC                   |
 *      |         DAC_R           |             nC            |       nC                   |
 *      |         DAC_L           |             nC            |       nC                   |
 *      |         SPK_1           |             nC            |       Speaker 1            |
 *      |         GND             |             GND           |       nC                   |
 *      |         SPK_2           |             nC            |       Speaker 2            |
 *       ----------------------------------------------------------------------------------
 *       
 *       NOTE: The 1kOhm Resistor goes to Arduino Pin D8       
 *       DFPlayer Mini Pi RX        ->          1kOhm Res       ->        Arduino Pin D8
 *      
 */
void Init_DFPlayerMini()
{
  /* ****************************** INIT SOUND MODULE DFPPLAYER ****************************** */
  #ifdef DFP_PLAYER
    memset(&gSoundMap, 0, sizeof(DIYinoSoundMap));
    // Sound font features. Numbers here are arbitrary.
    // These values should be adjusted to match how your
    // sound module is programmed.
    gSoundMap.Features.FontIdsPerFont = 1;
    gSoundMap.Features.HumSoundsPerFont = 1;
    gSoundMap.Features.PowerUpSoundsPerFont = 0;
    gSoundMap.Features.PowerDownSoundsPerFont = 1;
    gSoundMap.Features.ClashSoundsPerFont = 1;
    gSoundMap.Features.SwingSoundsPerFont = 1;
    gSoundMap.Features.LockupSoundsPerFont = 0;
    gSoundMap.Features.BlasterSoundsPerFont = 0;
    gSoundMap.Features.ForceSoundsPerFont = 0;
    gSoundMap.Features.CustomSoundsPerFont = 0;
    gSoundMap.Features.MenuSounds = 0;
  
    //Sound locations
    gSoundMap.Locations.BaseAddr = 0;
    gSoundMap.Locations.BlasterBase = 0;
    gSoundMap.Locations.BootBase = 1;
    gSoundMap.Locations.ClashBase = 2;
    gSoundMap.Locations.SwingBase = 7;
    gSoundMap.Locations.LockupBase = 0;
    gSoundMap.Locations.PowerupBase = 5;
    gSoundMap.Locations.PowerdownBase = 4;
    gSoundMap.Locations.HumBase = 6;
    gSoundMap.Locations.FontIdBase = 0;
    gSoundMap.Locations.CustomBase = 0;
    gSoundMap.Locations.MenuBase = 0;

    /* wait for changes to take effect */
    delay(200);
    /* Create the sound player */
    gpSoundPlayer = new DIYinoSoundPlayer(TX_PIN, RX_PIN, &gSoundMap, BUSY_PIN, LOW);
    /* Initialize the player */
    gpSoundPlayer->Init();

    gpSoundPlayer->SetVolume(20);
    delay(1000);
  #endif
}

