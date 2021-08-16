/****************************************************************************************************************************
  LittleFS_Mbed_RP2040.h - Filesystem wrapper for LittleFS on the Mbed RP2040
  
  For MBED RP2040-based boards such as Nano_RP2040_Connect, RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040.
  Written by Khoi Hoang

  Built by Khoi Hoang https://github.com/khoih-prog/LittleFS_Mbed_RP2040
  Licensed under MIT license

  Version: 1.0.1

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      11/06/2021 Initial coding to support MBED RP2040-based boards such as RASPBERRY_PI_PICO. etc.
  1.0.1   K Hoang      16/08/2021 Fix FORCE_REFORMAT bug in example
*****************************************************************************************************************************/

#ifndef _LITTLEFS_MBED_RP2040_H
#define _LITTLEFS_MBED_RP2040_H

#if ( defined(ARDUINO_ARCH_RP2040) && defined(ARDUINO_ARCH_MBED) ) 
  #warning Use MBED RP2040 (such as NANO_RP2040_CONNECT, RASPBERRY_PI_PICO) and LittleFS
#else
  #error This code is intended to run on the MBED RASPBERRY_PI_PICO platform! Please check your Tools->Board setting. 
#endif

#ifndef LFS_MBED_RP2040_VERSION
  #define LFS_MBED_RP2040_VERSION       "LittleFS_Mbed_RP2040 v1.0.1"
#endif

#ifndef LFS_MBED_RP2040_DEBUG
  #define LFS_MBED_RP2040_DEBUG      0
#endif

#include <Arduino.h>

#include "LittleFS_Mbed_RP2040_Debug.h"

// For Arduino' arduino-mbed core
// To check and determine if we need to init LittleFS here
#if MBED_RP2040_INITIALIZED
  #define MBED_LITTLEFS_NEED_INIT     false
  #warning MBED_RP2040_INITIALIZED in another place
#else
  // Better to delay until init done
  #if defined(MBED_RP2040_INITIALIZED)
    #undef MBED_RP2040_INITIALIZED
  #endif
  #define MBED_RP2040_INITIALIZED           true
  
  #define MBED_LITTLEFS_NEED_INIT     true
  
  #warning MBED_RP2040_INITIALIZED in LittleFS_Mbed_RP2040
#endif

#if MBED_LITTLEFS_NEED_INIT

  //Use LittleFS for MBED RPI Pico
  #include "FlashIAPBlockDevice.h"
  #include "LittleFileSystem.h"
  #include "mbed.h"

  #include <stdio.h>
  #include <errno.h>
  #include <functional>

  #include "BlockDevice.h"

  #if !defined(RP2040_FLASH_SIZE)
    #define RP2040_FLASH_SIZE         (2 * 1024 * 1024)
  #endif

  #if !defined(RP2040_FS_LOCATION_END)
    #define RP2040_FS_LOCATION_END    RP2040_FLASH_SIZE
  #endif

  #if !defined(RP2040_FS_SIZE_KB)
    // Using default 64KB for LittleFS
    #define RP2040_FS_SIZE_KB       (64)
    #warning Using default RP2040_FS_SIZE_KB == 64KB
  #else
    #warning Using RP2040_FS_SIZE_KB defined in external code 
  #endif

  #if !defined(RP2040_FS_START)
    #define RP2040_FS_START           (RP2040_FLASH_SIZE - (RP2040_FS_SIZE_KB * 1024))
  #endif

  #if !defined(FORCE_REFORMAT)
    #define FORCE_REFORMAT            false
  #elif FORCE_REFORMAT
    #warning FORCE_REFORMAT enable. Are you sure ?
  #endif

  #define MBED_LITTLEFS_FILE_NAME     "littlefs"
  #define MBED_LITTLEFS_FILE_PREFIX   "/" MBED_LITTLEFS_FILE_NAME

#endif

static FlashIAPBlockDevice bd(XIP_BASE + RP2040_FS_START, (RP2040_FS_SIZE_KB * 1024));
static mbed::LittleFileSystem fs(MBED_LITTLEFS_FILE_NAME);

class LittleFS_MBED
{
public:
  LittleFS_MBED()
  {
    _size     = RP2040_FS_SIZE_KB * 1024;
    _mounted  = false;
  }

  ~LittleFS_MBED() 
  {
    if (_mounted) 
    {
      unmount();      
    }
  }
  
  bool init();
  bool mount();
  bool unmount();
  
private:

  uint32_t _size;

  bool     _mounted;  
};

#include "LittleFS_Mbed_RP2040.hpp"

#endif // ifndef _LITTLEFS_MBED_RP2040_H
