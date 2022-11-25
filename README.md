# LittleFS_Mbed_RP2040 Library

[![arduino-library-badge](https://www.ardu-badge.com/badge/LittleFS_Mbed_RP2040.svg?)](https://www.ardu-badge.com/LittleFS_Mbed_RP2040)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/LittleFS_Mbed_RP2040.svg)](https://github.com/khoih-prog/LittleFS_Mbed_RP2040/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/LittleFS_Mbed_RP2040/blob/main/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/LittleFS_Mbed_RP2040.svg)](http://github.com/khoih-prog/LittleFS_Mbed_RP2040/issues)


<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Donate to my libraries using BuyMeACoffee" style="height: 50px !important;width: 181px !important;" ></a>
<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://img.shields.io/badge/buy%20me%20a%20coffee-donate-orange.svg?logo=buy-me-a-coffee&logoColor=FFDD00" style="height: 20px !important;width: 200px !important;" ></a>
<a href="https://profile-counter.glitch.me/khoih-prog/count.svg" title="Total khoih-prog Visitor count"><img src="https://profile-counter.glitch.me/khoih-prog/count.svg" style="height: 30px;width: 200px;"></a>
<a href="https://profile-counter.glitch.me/khoih-prog-LittleFS_Mbed_RP2040/count.svg" title="LittleFS_Mbed_RP2040 Visitor count"><img src="https://profile-counter.glitch.me/khoih-prog-LittleFS_Mbed_RP2040/count.svg" style="height: 30px;width: 200px;"></a>


---
---

## Table of Contents

* [Important Notes](#important-notes)
* [Why do we need this LittleFS_Mbed_RP2040 library](#why-do-we-need-this-littlefs_mbed_rp2040-library)
  * [Features](#features)
  * [Currently supported Boards](#currently-supported-boards)
* [Changelog](changelog.md)
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [Examples](#examples)
  * [  1. LittleFS_Counting](examples/LittleFS_Counting)
  * [  2. LittleFS_Test](examples/LittleFS_Test)
* [Example LittleFS_Test](#example-littlefs_test)
* [Debug Terminal Output Samples](#debug-terminal-output-samples)
  * [1. LittleFS_Counting on RaspberryPi Pico](#1-littlefs_counting-on-raspberrypi-pico)
  * [2. LittleFS_Test on RaspberryPi Pico](#2-littlefs_test-on-raspberrypi-pico)
* [Debug](#debug)
* [Troubleshooting](#troubleshooting)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright)

---
---

### Important Notes

The LittleFS of the new **Nano_RP2040_Connect** board (see picture below), using `ISSI` Flash chip, is currently **not working** with [`Arduino mbed_rp2040 core 2.4.1+`](https://github.com/arduino/ArduinoCore-mbed/releases/tag/2.4.1). Please downgrade to [`Arduino mbed_rp2040 core 2.3.1`](https://github.com/arduino/ArduinoCore-mbed/releases/tag/2.3.1)

<p align="center">
    <img src="https://github.com/khoih-prog/LittleFS_Mbed_RP2040/raw/main/pics/New_Board.png">
</p>

Check [**RP2040 Connect board has faulty components in newest purchase** #318](https://github.com/arduino/ArduinoCore-mbed/issues/318#) for more information of when and how the issue will be fixed.

The old board (see picture below), using `Adesto` Flash chip, is currently working with [`Arduino mbed_rp2040 core 2.4.1+`](https://github.com/arduino/ArduinoCore-mbed/releases/tag/2.4.1).


<p align="center">
    <img src="https://github.com/khoih-prog/LittleFS_Mbed_RP2040/raw/main/pics/Old_Board.png">
</p>

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


## Prerequisites

1. [`Arduino IDE 1.8.19+` for Arduino](https://www.arduino.cc/en/Main/Software)
2. [`Arduino mbed_rp2040 core 2.3.1-`](https://github.com/arduino/ArduinoCore-mbed) for RP2040-based boards using `ISSI` Flash chip, see [New board](pics/New_Board.png), such as **Arduino Nano RP2040 Connect, RASPBERRY_PI_PICO, etc.**. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-mbed.svg)](https://github.com/arduino/ArduinoCore-mbed/releases/latest)
3. [`Arduino mbed_rp2040 core 2.4.1+`](https://github.com/arduino/ArduinoCore-mbed) for Arduino (Use Arduino Board Manager) RP2040-based boards using `Adesto` Flash chip, see [Old board](pics/Old_Board.png), such as **Arduino Nano RP2040 Connect, RASPBERRY_PI_PICO, etc.**. Latest release is [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-mbed.svg)](https://github.com/arduino/ArduinoCore-mbed/releases/latest)

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
3. Install [**LittleFS_Mbed_RP2040** library](https://registry.platformio.org/libraries/khoih-prog/LittleFS_Mbed_RP2040) by using [Library Manager](https://registry.platformio.org/libraries/khoih-prog/LittleFS_Mbed_RP2040/installation). Search for **LittleFS_Mbed_RP2040** in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)


---
---


### Examples 

 1. [LittleFS_Counting](examples/LittleFS_Counting)
 2. [LittleFS_test](examples/LittleFS_Test)

---
---

### Example [Littlefs_Test](examples/Littlefs_Test)

https://github.com/khoih-prog/LittleFS_Mbed_RP2040/blob/088cf4bbbc48a1bed4f4ac0c7f94e7f92e32d092/examples/LittleFS_Test/LittleFS_Test.ino#L11-L359

---
---

### Debug Terminal Output Samples

### 1. LittleFS_Counting on RaspberryPi Pico

The following is the sample terminal output when running example [LittleFS_Counting](examples/LittleFS_Counting) on MBED RaspberryPi Pico

```cpp
Start LittleFS_Counting on RaspberryPi Pico
LittleFS_Mbed_RP2040 v1.1.0
[LFS] LittleFS size (KB) = 256
[LFS] LittleFS Mount OK
Deleting file: /littlefs/counts.txt => OK
Times have been run = 1
 => Open to write OK

Start LittleFS_Counting on RaspberryPi Pico
LittleFS_Mbed_RP2040 v1.1.0
[LFS] LittleFS size (KB) = 256
[LFS] LittleFS Mount OK
 => Open to read OK
Times have been run = 2
 => Open to write OK

Start LittleFS_Counting on RaspberryPi Pico
LittleFS_Mbed_RP2040 v1.1.0
[LFS] LittleFS size (KB) = 256
[LFS] LittleFS Mount OK
 => Open to read OK
Times have been run = 3
 => Open to write OK
```

---

### 2. LittleFS_Test on RaspberryPi Pico

The following is the sample terminal output when running example [LittleFS_Test](examples/LittleFS_Test) on MBED RaspberryPi Pico


```cpp
Start LittleFS_Test on RaspberryPi Pico
LittleFS_Mbed_RP2040 v1.1.0
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
4. Add astyle using `allman` style. Restyle the library

---
---

### Contributions and Thanks

Many thanks for everyone for bug reporting, new feature suggesting, testing and contributing to the development of this library.

1. Thanks to [Maximilian Gerhardt](https://github.com/maxgerhardt) to create bug report [RP2040_RTC_Time crashes Pico, does not work #3](https://github.com/khoih-prog/RP2040_RTC/issues/3) and help investigate and fix the bug, leading to v1.0.3

<table>
  <tr>
    <td align="center"><a href="https://github.com/maxgerhardt"><img src="https://github.com/maxgerhardt.png" width="100px;" alt="maxgerhardt"/><br /><sub><b>Maximilian Gerhardt</b></sub></a><br /></td>
  </tr> 
</table>



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

Copyright (c) 2021- Khoi Hoang


