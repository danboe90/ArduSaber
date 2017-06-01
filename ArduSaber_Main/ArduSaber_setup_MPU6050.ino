
/**
 *      @brief      This functions initializes the entire MPU6050 Module
 *      
 *      PINNING
 *      nC...not Connected
 *      
 *       -----------------------------------------------------
 *      |     MPU6050 Pin         |         Arduino Pin       |
 *       -----------------------------------------------------
 *      |         VCC             |             5V            |
 *      |         GND             |             GND           |
 *      |         SCL             |             A5            |
 *      |         SDA             |             A4            |
 *      |         XDA             |             nC            |
 *      |         XCL             |             nC            |
 *      |         AD0             |             nC            |
 *      |         INT             |             nC            |
 *       -----------------------------------------------------
 */
void Init_MPU6050()
{
  /* ****************************** INIT OF THE MPU6050 ****************************** */
  /* Set MPU6050 swing tolerance threasholds here. */
  /* Tweak as needed to adjust sensitivity */
  gToleranceData.mSwingLarge  = LARGE_TRESHOLD;
  gToleranceData.mSwingMedium = MEDIUM_TRESHOLD;
  gToleranceData.mSwingSmall  = SMALL_TRESHOLD;
  /* Set MPU6050 calibration data here. */
  /* Tweak as needed to improve accuracy */
  gMpuCalData.mAccelXOffset = -1848;            /* was: -1848 */
  gMpuCalData.mAccelYOffset = -5409;            /* was: -5409 */
  gMpuCalData.mAccelZOffset = 1640;             /* was: 1640  */
  gMpuCalData.mGyXOffset = -5;
  gMpuCalData.mGyYOffset = 48;
  gMpuCalData.mGyZOffset = 23;

  /* ****************************** INIT OF THE MOTION-MANAGER ****************************** */ 
  apMotion = new Mpu6050MotionManager(&gToleranceData, &gMpuCalData);
  apMotion->Init();
}

