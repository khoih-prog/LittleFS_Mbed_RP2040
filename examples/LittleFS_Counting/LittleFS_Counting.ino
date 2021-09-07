/****************************************************************************************************************************
  LittleFS_Counting.ino - Filesystem wrapper for LittleFS on the Mbed RP2040
  
  For MBED RP2040-based boards such as Nano_RP2040_Connect, RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040.
  Written by Khoi Hoang

  Built by Khoi Hoang https://github.com/khoih-prog/LittleFS_Mbed_RP2040
  Licensed under MIT license

  Version: 1.0.2

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      11/06/2021 Initial coding to support MBED RP2040-based boards such as RASPBERRY_PI_PICO. etc.
  1.0.1   K Hoang      16/08/2021 Fix FORCE_REFORMAT bug in example
  1.0.2   K Hoang      07/09/2021 Add mbed and ArduinoCore-mbed to architectures
*****************************************************************************************************************************/

#define _LFS_LOGLEVEL_          1
#define RP2040_FS_SIZE_KB       64

#define FORCE_REFORMAT          false

#include <LittleFS_Mbed_RP2040.h>

#define START_COUNT_OVER      false

LittleFS_MBED *myFS;

void setup() 
{
  Serial.begin(115200);
  while (!Serial)

  delay(1000);

  Serial.print("\nStart LittleFS_Counting on "); Serial.println(BOARD_NAME);
  Serial.println(LFS_MBED_RP2040_VERSION);

  myFS = new LittleFS_MBED();

  if (!myFS->init()) 
  {
    Serial.println("LITTLEFS Mount Failed");
    
    return;
  }

  char fileName[] = MBED_LITTLEFS_FILE_PREFIX "/counts.txt";

  #define BUF_SIZE      32
  
  char buff[BUF_SIZE];
  int count = 1;

#if  START_COUNT_OVER
  Serial.print("Deleting file: "); Serial.print(fileName);
  
  if (remove(fileName) == 0) 
  {
    Serial.println(" => OK");
  }
  else
  {
    Serial.println(" => Failed");
  }
#endif
  
  FILE *file = fopen(fileName, "r");
  
  if (file) 
  {
    Serial.println(" => Open to read OK");
    
    bzero(buff, BUF_SIZE);
    
    uint32_t numRead = fread((uint8_t *) buff, BUF_SIZE - 1, 1, file);
   
    if ( numRead )
    {
      sscanf(buff, "%d", &count);
      //Serial.print("Times have been run = "); Serial.println(count);
    }
    
    fclose(file);
  }

  Serial.print("Times have been run = "); Serial.println(count);
  
  sprintf(buff, "%d\n", ++count);
  
  file = fopen(fileName, "w");
  
  if (file) 
  {
    Serial.println(" => Open to write OK");
    
    fwrite((uint8_t *) buff, 1, BUF_SIZE - 1, file) ;
    fclose(file);
  }
}

void loop() 
{
}
