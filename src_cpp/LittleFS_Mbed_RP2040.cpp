/****************************************************************************************************************************
  LittleFS_Mbed_RP2040.cpp - Filesystem wrapper for LittleFS on the Mbed RP2040
  
  For MBED RP2040-based boards such as Nano_RP2040_Connect, RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040.
  Written by Khoi Hoang

  Built by Khoi Hoang https://github.com/khoih-prog/LittleFS_Mbed_RP2040
  Licensed under MIT license

  Version: 1.0.3

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      11/06/2021 Initial coding to support MBED RP2040-based boards such as RASPBERRY_PI_PICO. etc.
  1.0.1   K Hoang      16/08/2021 Fix FORCE_REFORMAT bug in example
  1.0.2   K Hoang      07/09/2021 Add mbed and ArduinoCore-mbed to architectures
  1.0.3   K Hoang      02/11/2021 Fix crashing issue for new flash
*****************************************************************************************************************************/

#include "LittleFS_Mbed_RP2040.h"
 
bool LittleFS_MBED::init()
{
  LFS_LOGERROR1("LittleFS size (KB) = ", RP2040_FS_SIZE_KB);

#if FORCE_REFORMAT
  fs.reformat(&bd);
#endif  

  return mount();
}

bool LittleFS_MBED::mount()
{
  if (!_mounted)
  {
    int err = fs.mount(&bd);

    LFS_LOGERROR(err ? "LittleFS Mount Fail" : "LittleFS Mount OK");

    if (err)
    {
      // Reformat if we can't mount the filesystem
      LFS_LOGERROR("Formatting... ");
      LFS_FLUSH();

      err = fs.reformat(&bd);
    }

    _mounted = (err == 0);
  
    if (!_mounted)
    {
      LFS_LOGERROR("\nLittleFS error");
    } 
  }
  
  return _mounted;
}

bool LittleFS_MBED::unmount()
{
  if (_mounted)
  {
    int err = fs.unmount();
  
    LFS_LOGERROR1("Unmount FS ", err < 0 ? "Fail" : "OK");
 
    if (err < 0)
    {   
      return false;
    }
  }
  
  _mounted = false;
  
  return true;
}


