# LittleFS_Mbed_RP2040 Library

[![arduino-library-badge](https://www.ardu-badge.com/badge/LittleFS_Mbed_RP2040.svg?)](https://www.ardu-badge.com/LittleFS_Mbed_RP2040)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/LittleFS_Mbed_RP2040.svg)](https://github.com/khoih-prog/LittleFS_Mbed_RP2040/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/LittleFS_Mbed_RP2040/blob/main/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/LittleFS_Mbed_RP2040.svg)](http://github.com/khoih-prog/LittleFS_Mbed_RP2040/issues)

---
---

## Table of Contents

* [Why do we need this LittleFS_Mbed_RP2040 library](#why-do-we-need-this-littlefs_mbed_rp2040-library)
  * [Features](#features)
  * [Currently supported Boards](#currently-supported-boards)
* [Changelog](#changelog)
  * [Releases v1.0.2](#releases-v102)
  * [Releases v1.0.1](#releases-v101)
  * [Initial Releases v1.0.0](#initial-releases-v100)
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [HOWTO Fix `Multiple Definitions` Linker Error](#howto-fix-multiple-definitions-linker-error)
* [Examples](#examples)
  * [  1. LittleFS_Counting](examples/LittleFS_Counting)
  * [  2. LittleFS_Test](examples/LittleFS_Test)
* [Example LittleFS_Test](#example-littlefs_test)
* [Debug Terminal Output Samples](#debug-terminal-output-samples)
  * [1. LittleFS_Counting on RaspberryPi Pico](#1-littlefs_counting-on-raspberrypi-pico)
  * [2. LittleFS_Test on RaspberryPi Pico](#2-littlefs_test-on-raspberrypi-pico)
* [Debug](#debug)
* [Troubleshooting](#troubleshooting)
* [Releases](#releases)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright)

---
---

### Why do we need this [LittleFS_Mbed_RP2040 library](https://github.com/khoih-prog/LittleFS_Mbed_RP2040)

## Features

This library is just a simple LittleFS wrapper to facilitate your usage of LittleFS for the onboard flash on **MBED RP2040-based boards such as Nano_RP2040_Connect, RASPBERRY_PI_PICO**, using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed)

The filesystem access uses normal [POSIX APIs](https://www.tutorialspoint.com/c_standard_library/stdio_h.htm) or [mbed FileSystem APIs](https://os.mbed.com/docs/mbed-os/v6.10/apis/file-system-apis.html)

---

### Currently supported Boards

1. RP2040-based boards such as **Nano_RP2040_Connect, RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, etc. using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed)

---
---

## Changelog

### Releases v1.0.2

1. Add mbed, mbed_nano and ArduinoCore-mbed to architectures of `library.properties`

### Releases v1.0.1

1. Fix FORCE_REFORMAT bug in example
2. Change default RP2040_FS_SIZE_KB from 256KB to 64KB to avoid crash in some new boards. Check [MBED crash - RP2040 rebooting #1](https://github.com/khoih-prog/LittleFS_Mbed_RP2040/issues/1)

### Initial Releases v1.0.0

1. Initial coding to support RP2040-based boards such as **Nano_RP2040_Connect, RASPBERRY_PI_PICO**, etc. using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed)


---
---

## Prerequisites

1. [`Arduino IDE 1.8.15+` for Arduino](https://www.arduino.cc/en/Main/Software)
2. [`Arduino mbed_rp2040 core 2.4.1+`](https://github.com/arduino/ArduinoCore-mbed) for Arduino (Use Arduino Board Manager) RP2040-based boards, such as **Arduino Nano RP2040 Connect, RASPBERRY_PI_PICO, etc.**. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-mbed.svg)](https://github.com/arduino/ArduinoCore-mbed/releases/latest)

---
---

## Installation

### Use Arduino Library Manager

The best and easiest way is to use `Arduino Library Manager`. Search for [**LittleFS_Mbed_RP2040**](https://github.com/khoih-prog/LittleFS_Mbed_RP2040), then select / install the latest version.
You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/LittleFS_Mbed_RP2040.svg?)](https://www.ardu-badge.com/LittleFS_Mbed_RP2040) for more detailed instructions.

### Manual Install

Another way to install is to:

1. Navigate to [**LittleFS_Mbed_RP2040**](https://github.com/khoih-prog/LittleFS_Mbed_RP2040) page.
2. Download the latest release `LittleFS_Mbed_RP2040-main.zip`.
3. Extract the zip file to `LittleFS_Mbed_RP2040-main` directory 
4. Copy whole `LittleFS_Mbed_RP2040-main` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**LittleFS_Mbed_RP2040** library](https://platformio.org/lib/show/12420/LittleFS_Mbed_RP2040) by using [Library Manager](https://platformio.org/lib/show/12420/LittleFS_Mbed_RP2040/installation). Search for **LittleFS_Mbed_RP2040** in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)


---
---


### HOWTO Fix `Multiple Definitions` Linker Error

The current library implementation, using **xyz-Impl.h instead of standard xyz.cpp**, possibly creates certain `Multiple Definitions` Linker error in certain use cases. Although it's simple to just modify several lines of code, either in the library or in the application, the library is adding 2 more source directories

1. **scr_h** for new h-only files
2. **src_cpp** for standard h/cpp files

besides the standard **src** directory.

To use the **old standard cpp** way, locate this library' directory, then just 

1. **Delete the all the files in src directory.**
2. **Copy all the files in src_cpp directory into src.**
3. Close then reopen the application code in Arduino IDE, etc. to recompile from scratch.

To re-use the **new h-only** way, just 

1. **Delete the all the files in src directory.**
2. **Copy the files in src_h directory into src.**
3. Close then reopen the application code in Arduino IDE, etc. to recompile from scratch.

---
---


### Examples 

 1. [LittleFS_Counting](examples/LittleFS_Counting)
 2. [LittleFS_test](examples/LittleFS_Test)

---
---

### Example [Littlefs_Test](examples/Littlefs_Test)

```
#define _LFS_LOGLEVEL_          1
#define RP2040_FS_SIZE_KB       64

#define FORCE_REFORMAT          false

#include <LittleFS_Mbed_RP2040.h>

LittleFS_MBED *myFS;

void readCharsFromFile(const char * path) 
{
  Serial.print("readCharsFromFile: "); Serial.print(path);

  FILE *file = fopen(path, "r");
  
  if (file) 
  {
    Serial.println(" => Open OK");
  }
  else
  {
    Serial.println(" => Open Failed");
    return;
  }

  char c;

  while (true) 
  {
    c = fgetc(file);
    
    if ( feof(file) ) 
    { 
      break;
    }
    else   
      Serial.print(c);
  }
   
  fclose(file);
}

void readFile(const char * path) 
{
  Serial.print("Reading file: "); Serial.print(path);

  FILE *file = fopen(path, "r");
  
  if (file) 
  {
    Serial.println(" => Open OK");
  }
  else
  {
    Serial.println(" => Open Failed");
    return;
  }

  char c;
  uint32_t numRead = 1;
  
  while (numRead) 
  {
    numRead = fread((uint8_t *) &c, sizeof(c), 1, file);

    if (numRead)
      Serial.print(c);
  }
  
  fclose(file);
}

void writeFile(const char * path, const char * message, size_t messageSize) 
{
  Serial.print("Writing file: "); Serial.print(path);

  FILE *file = fopen(path, "w");
  
  if (file) 
  {
    Serial.println(" => Open OK");
  }
  else
  {
    Serial.println(" => Open Failed");
    return;
  }
 
  if (fwrite((uint8_t *) message, 1, messageSize, file)) 
  {
    Serial.println("* Writing OK");
  } 
  else 
  {
    Serial.println("* Writing failed");
  }
  
  fclose(file);
}

void appendFile(const char * path, const char * message, size_t messageSize) 
{
  Serial.print("Appending file: "); Serial.print(path);

  FILE *file = fopen(path, "a");
  
  if (file) 
  {
    Serial.println(" => Open OK");
  }
  else
  {
    Serial.println(" => Open Failed");
    return;
  }

  if (fwrite((uint8_t *) message, 1, messageSize, file)) 
  {
    Serial.println("* Appending OK");
  } 
  else 
  {
    Serial.println("* Appending failed");
  }
   
  fclose(file);
}

void deleteFile(const char * path) 
{
  Serial.print("Deleting file: "); Serial.print(path);
  
  if (remove(path) == 0) 
  {
    Serial.println(" => OK");
  }
  else
  {
    Serial.println(" => Failed");
    return;
  }
}

void renameFile(const char * path1, const char * path2) 
{
  Serial.print("Renaming file: "); Serial.print(path1);
  Serial.print(" to: "); Serial.print(path2);
  
  if (rename(path1, path2) == 0) 
  {
    Serial.println(" => OK");
  }
  else
  {
    Serial.println(" => Failed");
    return;
  }
}

void testFileIO(const char * path) 
{
  Serial.print("Testing file I/O with: "); Serial.print(path);

  #define BUFF_SIZE     512
  
  static uint8_t buf[BUFF_SIZE];
  
  FILE *file = fopen(path, "w");
  
  if (file) 
  {
    Serial.println(" => Open OK");
  }
  else
  {
    Serial.println(" => Open Failed");
    return;
  }

  size_t i;
  Serial.println("- writing" );
  
  uint32_t start = millis();

  size_t result = 0;

  // Write a file only 1/4 of RP2040_FS_SIZE_KB
  for (i = 0; i < RP2040_FS_SIZE_KB / 2; i++) 
  {
    result = fwrite(buf, BUFF_SIZE, 1, file);

    if ( result != 1)
    {
      Serial.print("Write result = "); Serial.println(result);
      Serial.print("Write error, i = "); Serial.println(i);

      break;
    }
  }
  
  Serial.println("");
  uint32_t end = millis() - start;
  
  Serial.print(i / 2);
  Serial.print(" Kbytes written in (ms) ");
  Serial.println(end);
  
  fclose(file);

  printLine();

  /////////////////////////////////

  file = fopen(path, "r");
  
  start = millis();
  end = start;
  i = 0;
  
  if (file) 
  {
    start = millis();
    Serial.println("- reading" );

    result = 0;

    fseek(file, 0, SEEK_SET);

    // Read file only 1/4 of RP2040_FS_SIZE_KB
    for (i = 0; i < RP2040_FS_SIZE_KB / 2; i++) 
    {
      result = fread(buf, BUFF_SIZE, 1, file);

      if ( result != 1 )
      {
        Serial.print("Read result = "); Serial.println(result);
        Serial.print("Read error, i = "); Serial.println(i);

        break;
      }
    }
      
    Serial.println("");
    end = millis() - start;
    
    Serial.print((i * BUFF_SIZE) / 1024);
    Serial.print(" Kbytes read in (ms) ");
    Serial.println(end);
    
    fclose(file);
  } 
  else 
  {
    Serial.println("- failed to open file for reading");
  }
}

void printLine()
{
  Serial.println("====================================================");
}

void setup() 
{
  Serial.begin(115200);
  while (!Serial)

  delay(1000);

  Serial.print("\nStart LittleFS_Test on "); Serial.println(BOARD_NAME);
  Serial.println(LFS_MBED_RP2040_VERSION);

  myFS = new LittleFS_MBED();

  if (!myFS->init()) 
  {
    Serial.println("LITTLEFS Mount Failed");
    
    return;
  }

  char fileName1[] = MBED_LITTLEFS_FILE_PREFIX "/hello1.txt";
  char fileName2[] = MBED_LITTLEFS_FILE_PREFIX "/hello2.txt";
  
  char message[]  = "Hello from " BOARD_NAME "\n";
   
  printLine();
  writeFile(fileName1, message, sizeof(message));
  printLine();
  readFile(fileName1);
  printLine();

  appendFile(fileName1, message, sizeof(message));
  printLine();
  readFile(fileName1);
  printLine();

  renameFile(fileName1, fileName2);
  printLine();
  readCharsFromFile(fileName2);
  printLine();

  deleteFile(fileName2);
  printLine();
  readFile(fileName2);
  printLine();

  testFileIO(fileName1);
  printLine();
  testFileIO(fileName2);
  printLine();
  deleteFile(fileName1);
  printLine();
  deleteFile(fileName2);
  printLine();

  Serial.println( "\nTest complete" );
}

void loop() 
{
}
```
---
---

### Debug Terminal Output Samples

### 1. LittleFS_Counting on RaspberryPi Pico

The following is the sample terminal output when running example [LittleFS_Counting](examples/LittleFS_Counting) on MBED RaspberryPi Pico

```
Start LittleFS_Counting on RaspberryPi Pico
LittleFS_Mbed_RP2040 v1.0.2
[LFS] LittleFS size (KB) = 256
[LFS] LittleFS Mount OK
Deleting file: /littlefs/counts.txt => OK
Times have been run = 1
 => Open to write OK

Start LittleFS_Counting on RaspberryPi Pico
LittleFS_Mbed_RP2040 v1.0.2
[LFS] LittleFS size (KB) = 256
[LFS] LittleFS Mount OK
 => Open to read OK
Times have been run = 2
 => Open to write OK

Start LittleFS_Counting on RaspberryPi Pico
LittleFS_Mbed_RP2040 v1.0.2
[LFS] LittleFS size (KB) = 256
[LFS] LittleFS Mount OK
 => Open to read OK
Times have been run = 3
 => Open to write OK
```

### 2. LittleFS_Test on RaspberryPi Pico

The following is the sample terminal output when running example [LittleFS_Test](examples/LittleFS_Test) on MBED RaspberryPi Pico


```
Start LittleFS_Test on RaspberryPi Pico
LittleFS_Mbed_RP2040 v1.0.2
[LFS] LittleFS size (KB) = 256
[LFS] LittleFS Mount OK
====================================================
Writing file: /littlefs/hello1.txt => Open OK
* Writing OK
====================================================
Reading file: /littlefs/hello1.txt => Open OK
Hello from RaspberryPi Pico
====================================================
Appending file: /littlefs/hello1.txt => Open OK
* Appending OK
====================================================
Reading file: /littlefs/hello1.txt => Open OK
Hello from RaspberryPi Pico
Hello from RaspberryPi Pico
====================================================
Renaming file: /littlefs/hello1.txt to: /littlefs/hello2.txt => OK
====================================================
readCharsFromFile: /littlefs/hello2.txt => Open OK
Hello from RaspberryPi Pico
Hello from RaspberryPi Pico
====================================================
Deleting file: /littlefs/hello2.txt => OK
====================================================
Reading file: /littlefs/hello2.txt => Open Failed
====================================================
Testing file I/O with: /littlefs/hello1.txt => Open OK
- writing

64 Kbytes written in (ms) 847
====================================================
- reading

64 Kbytes read in (ms) 18
====================================================
Testing file I/O with: /littlefs/hello2.txt => Open OK
- writing

64 Kbytes written in (ms) 847
====================================================
- reading

64 Kbytes read in (ms) 18
====================================================
Deleting file: /littlefs/hello1.txt => OK
====================================================
Deleting file: /littlefs/hello2.txt => OK
====================================================

Test complete

```

---
---

### Debug

Debug is enabled by default on Serial.

You can also change the debugging level (_LFS_LOGLEVEL_) from 0 to 4

```cpp
#define LFS_DEBUG_OUTPUT    Serial

// These define's must be placed at the beginning before #include "LittleFS_Mbed_RP2040.h"
// _LFS_LOGLEVEL_ from 0 to 4
#define _LFS_LOGLEVEL_      0
```

---

### Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of the core for Arduino boards.

Sometimes, the library will only work if you update the board core to the latest version because I am using newly added functions.


---
---

## Releases

### Releases v1.0.2

1. Add mbed, mbed_nano and ArduinoCore-mbed to architectures of `library.properties`

### Releases v1.0.1

1. Fix FORCE_REFORMAT bug in example
2. Change default RP2040_FS_SIZE_KB from 256KB to 64KB to avoid crash in some new boards. Check [MBED crash - RP2040 rebooting #1](https://github.com/khoih-prog/LittleFS_Mbed_RP2040/issues/1)

### Initial Releases v1.0.0

1. Initial coding to support RP2040-based boards such as **Nano_RP2040_Connect, RASPBERRY_PI_PICO**, etc. using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed)

---
---

### Issues

Submit issues to: [LittleFS_Mbed_RP2040 issues](https://github.com/khoih-prog/LittleFS_Mbed_RP2040/issues)

---

## TO DO

1. Search for bug and improvement.


---

## DONE

1. Basic LittleFS wrapper for **RP2040-based boards such as Nano_RP2040_Connect, RASPBERRY_PI_PICO**, using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed)
2. Add Version String 
3. Add Table of Contents

---
---

### Contributions and Thanks

Many thanks for everyone for bug reporting, new feature suggesting, testing and contributing to the development of this library.


---

## Contributing

If you want to contribute to this project:

- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

### License

- The library is licensed under [GPLv3](https://github.com/khoih-prog/LittleFS_Mbed_RP2040/blob/main/LICENSE)

---

## Copyright

Copyright 2021- Khoi Hoang


