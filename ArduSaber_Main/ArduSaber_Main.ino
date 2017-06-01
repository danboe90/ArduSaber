

/**
 *      @file       ArduSaber_Main.ino
 *      @author     danboe90
 *      @brief      This file contains the global variables, the setup() and the loop() routines.
 *                  setup() covers booting the ArduSaber, while loop() contains the execution of the 
 *                  state-machine.
 */


/*
 *            PINNING         FOR         PERIFERALS
 *            
 *            
 *            
 *            -------------------------------------------------------------------------
 *            |    ARDUINO PIN        |       PIN         |       HARDWARE            |
 *            -------------------------------------------------------------------------
 *            |         D2            |       /\/         |       /\/                 |
 *            |         D3            |       pB1         |       PushButton          |
 *            |         D4            |       CS          |       SD-Card Adapter     |
 *            |         D5            |       G           |       BUK453              |
 *            |         D6            |       /\/         |       /\/                 |       
 *            |         D7            |       /\/         |       /\/                 |
 *            |         D8            |       /\/         |       /\/                 |
 *            |         D9            |       R1          |       In to 2k7 resistor  |
 *            |         D10           |       /\/         |       /\/                 |
 *            |         D11           |       MOSI        |       SD-Card Adapter     |
 *            |         D12           |       MISO        |       SD-Card Adapter     |
 *            |         D13           |       SCK         |       SD-Card Adapter     |
 *            -------------------------------------------------------------------------
 *            |         A0            |       /\/         |       /\/                 |
 *            |         A1            |       /\/         |       /\/                 |
 *            |         A2            |       /\/         |       /\/                 |
 *            |         A3            |       /\/         |       /\/                 |
 *            |         A4            |       SDA         |       MPU6050             |
 *            |         A5            |       SCL         |       MPU6050             |
 *            |         A6            |       /\/         |       /\/                 |
 *            |         A7            |       /\/         |       /\/                 |
 *            -------------------------------------------------------------------------
 *            |         RST           |       /\/         |       /\/                 |
 *            -------------------------------------------------------------------------
 *            |         +5V           |       VCC         |       MPU6050             |
 *            |                       |       VCC         |       SD-Card Adapter     |
 *            -------------------------------------------------------------------------
 *            |         GND           |       GND         |       MPU6050             |
 *            |                       |       GND         |       SD-Card Adapter     |
 *            |                       |       pB2         |       PushButton          |
 *            -------------------------------------------------------------------------
 *            
 */


/* ****************************** DEFINES ****************************** */
#define SMALL_TRESHOLD          15    /* was: 5 */
#define MEDIUM_TRESHOLD         50    /* was: 9 */
#define LARGE_TRESHOLD          100   /* was: 18 */


#define SD_ChipSelectPin        4
#define LED_PIN1                5
#define BUSY_PIN                6
#define TX_PIN                  7     /* Transmit serial pin for DFPlayer */
#define RX_PIN                  8     /* Receive serial pin for DFPlayer */


#define DURATION_SWING          550          
#define DURATION_CLASH          300
#define DURATION_HUM            300

#define SUPRESS_CLASH           300
#define SUPRESS_SWING           566
#define SUPRESS_HUM             170




/* use one of the following defines for your sound-module */
#define DFP_PLAYER        /* for usage with DFPPlayer Mini Board */
//#define SPI_PLAYER      /* for usage with SD Card Adapter and Arduino as Audio-Output */




/* ****************************** INCLUDES ****************************** */
#include <Wire.h>
#include <USaber.h>
#ifdef SPI_PLAYER
  #include <TMRpcm.h>
  #include <SD.h>
  #include <SPI.h>
#endif
#ifdef DFP_PLAYER
  #include <TimerOne.h>
#endif
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>


/* ****************************** GLOBAL VARIABLES ****************************** */

/* Tolerance threshold data for MPU6050 motion manager */
MPU6050TolData gToleranceData;
/* Calibration data for MPU6050 motion manager */
MPU6050CalibrationData gMpuCalData;
/* Blade-Manager */
IBladeManager *apBlade;
/* Motion Manager */
AMotionManager *apMotion; 


/* Sound Manager SPI SD Card Adapter */
#ifdef SPI_PLAYER
  TMRpcm tmrpcm;
#endif
/* Sound Manager DFPPlayer Mini */
#ifdef DFP_PLAYER
  DIYinoSoundPlayer *gpSoundPlayer;
  static DIYinoSoundMap gSoundMap;
#endif

int pButton1    = 3;
int PRG_STATE = 0;
unsigned long gMotionUpdateTime;    /* Last time motion detection was updated */
unsigned long gLastClashTime;       /* Time when the last clash event occurred */
unsigned long gLastSwingTime;       /* Time when last swing event occurred */
unsigned long gLastHumTime;


/**
 *        @brief      This function is called as a while(1) loop. Continuously the PRG_STATE variable is checked.
 *                    PRG_STATE defines 
 */
void loop() {
  switch(PRG_STATE) {
    case 0:   saberIsOff();         /* turned OFF state */
              break;                
    case 1:   turnSaberOn();        /* turn ON state */
              break;
    case 2:   saberIsOn();          /* turned ON state */
              break;
    case 3:   turnSaberOff();       /* turn OFF state */
              break;
  }
}

















