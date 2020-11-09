# Micro-speech Example

This example is a micrphone-enabled vocal yes/no detector. It can tell apart *yes* and *no* from other sounds, and from one another, respectively.

Moreover, the demo can take input from either the microphone or from voice samples that we have loaded from the SD-Card.

You may also be interested in our wrapper repository [stm32-tflm-demos](https://github.com/PhilippvK/stm32-tflm-demos) for further details.

## Demo

![](micro_speech_demo.gif)

## Build
### Project configuration

First configure your board and features like CMSIS-NN, Benchmarking,... as explained [here](https://github.com/PhilippvK/stm32-tflm-demos/blob/master/docs/Usage.md).

Then you have to choose whether you want to use the board's microphone to record audio samples real-time, or load pre-recorded samples from the SD card. You make this choice by setting `FAKE_MIC` in `CMakeLists.txt` to either ON or OFF.
```
SET(FAKE_MIC OFF) # Use on board microphone
SET(FAKE_MIC ON) # Use samples from the SD card
```
By default, we are using the board's built-in microphone.
For actual samples and the required file structure, see the [media folder](https://github.com/PhilippvK/stm32-tflm-demos/blob/master/media/README.md). 

To better understand what we are doing, also see [microphone media](media/README.md).

Finally, simply run:
```
mkdir build
cd build
cmake -DTF_COMMIT=37c2bf5016fcbed261476386eced503e907cdc01 ..
make
make flash
```
For more details about build instruction, see the [main README](https://github.com/PhilippvK/stm32-tflm-demos/blob/master/README.md).

Other make targets we provide include `make debug` and `make convert` (to convert the `*.tflite` file into [tfite_micro_compiler](https://github.com/tum-ei-eda/tflite_micro_compiler) sources).

Fetching the dependencies (Tensorflow, STM32 Firmware) for the first time can take a very long time. You can either take a break or do the following to speed-up the process when using multiple examples:

```
export SOME_DIRECTORY=<CHOOSE_SOME_PATH>
git clone --recursive https://github.com/tensorflow/tensorflow.git $SOME_DIRECTORY/tensorflow
git clone https://github.com/mborgerding/kissfft.git $SOME_DIRECTORY/kissfft
git clone https://github.com/STMicroelectronics/STM32CubeF4 $SOME_DIRECTORY/STM32CubeF4
git clone https://github.com/STMicroelectronics/STM32CubeF7 $SOME_DIRECTORY/STM32CubeF7
git clone https://github.com/ARM-software/CMSIS_5.git $SOME_DIRECTORY/CMSIS_5
$SOME_DIRECTORY/tensorflow/tensorflow/lite/tools/make/download_dependencies.sh
```

After doing this a single time, just replace `cmake ..` with the following command in the future:

```
cmake -DTF_SRC=$SOME_DIRECTORY/tensorflow -DSTM32Cube_DIR=$SOME_DIRECTORY/STM32CubeF7 -DARM_CMSIS_SRC=$SOME_DIRECTORY/CMSIS_5 -DKISSFFT_SRC=$SOME_DIRECTORY/kissfft ..
```

**Tipp:** Swap out `STM32CubeF7` with `STM32CubeF4` when building for the `F413ZH` board!

### Rebuilding the project
It is mandatory to delete `CMakeCache.txt` after changing the STM32 board. Sometimes, you need to delete the `_deps` folder under `build` before running `cmake ..` again.
