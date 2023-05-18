MegunoLink library for Arduino Change History
=============================================

1.42
----
* Fixed compatibility issues with Arduino mbed platforms (e.g., Pi Pico). Thanks to [maxgerhardt](https://github.com/maxgerhardt) for identifying this problem. 
* Miscellaneous bug fixes and tidy up. 
* Added continuous integration work flow to build all examples on several platforms following suggestion from [maxgerhardt](https://github.com/maxgerhardt). 

1.41
----
* Updated examples to use ESP command handler for Tcp connections
* Excluded `MDNS.update();` call for ESP32, where it is not supported
* Fixed compile time error when sending SpecialParameters::CurrentTime to record table
* Fixed examples to use correct name for TcpCommandHandler on ESP hardware. 

1.40
----
* Added `RGBColor` class to send custom colors to plots and resolve build errors for some micros. 
* Added support for device file transfer visualizer. 
* New examples for speech and audio.
* Added support to expand command handler with pluggable modules. 
* Added support to send double precision values to XYPlots without casting. 
* Added core support for Udp and Tcp communications. 
* Cleaned up and consolodated plotting and table methods. 
* Fixed build errors for Teensy. 
* Fixed build errors for Due.
* Added library meta data file for PlatformIO/Visual Studio Code.
* Improvements to const-correctness. 
