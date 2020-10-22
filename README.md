# Micro-speech Example

This example is a micrphone-enabled vocal yes/no detector. It can tell apart *yes* and *no* from other sounds, and from one another, respectively.

Moreover, the demo can take input from either the microphone or from voice samples that we have loaded from the SD-Card.

## Build
### Project configuration
Firstly, you have to choose whether you want to use the board's microphone to record audio samples real-time, or load pre-recorded samples from the SD card. You make this choice by setting **FAKE_MIC** on line 72 in ```CMakeLists.txt``` to either ON or OFF.
```
SET(FAKE_MIC OFF) # Use on board microphone
SET(FAKE_MIC ON) # Use samples from the SD card
```
By default, we are using the board's built-in microphone.
For actual samples and the required file structure, see the [media folder](../../media/README.md). 

To better understand what we are doing, also see [microphone media](media/README.md).

Finally, simply run:
```
mkdir build
cd build
cmake -DTF_COMMIT=37c2bf5016fcbed261476386eced503e907cdc01 ..
make
make flash
```
For more details about build instruction, see the [main README](../../README.md).

You might have to run ```make flash``` several times if you get a deployment error.

### Rebuilding the project
It is mandatory to delete ```CMakeCache.txt``` before re-building your project. Moreover, you should delete the *_deps* folder under *build* before running ```cmake ..``` again.
