# Media

If microphone input is not deterministic/reliable enough for the 'Micro Speech' example, optionally real samples from the dataset can be fed into the neural network. The following sections should explain to to make use of this feature.

## Requirements

- (Empty) SD-Card (f.e. 2GB), formatted with FATFS
- Software:
  - `wget`, `tar` (should be installed by default on any UNIX system)
  - `sox` (See: [http://sox.sourceforge.net](http://sox.sourceforge.net))

## Configure CMake

0. Check if your board is compatible. See: [Boards](TODO)

1. Edit `CMakeLists.txt` an make sure, that the `FAKE_MIC` option is enabled

```
### Configure 'micro_speech' Example ###
SET(FAKE_MIC ON) # Use SD Card instead of Microphone
...
```

2. Recompile and flash the program
```
cd build
cmake ..
make flash
```

## Generate Files

**Hint:** You can skip this step you just using the contents of the `sd_card.zip` archive which can be downloaded [here](https://raw.githubusercontent.com/PhilippvK/stm32-tflm-demos/master/media/sd_card.zip).

### Why can't I just use the original dataset

STM's Board Support Package Driver does only support to play 16 bit stereo WAV-Files via the audio codec, the samples in the [original dataset](https://arxiv.org/abs/1804.03209) are encoded with a single channel (mono) 16 bit format.

### Steps

1. Download and extract dataset. As it's quite large, this will take some time. You may want to extract it somewhere outside of this repository, e.g. under `/tmp/`

```
mkdir /tmp/micro_speech_dataset
cd /tmp/micro_speech_dataset
wget http://download.tensorflow.org/data/speech_commands_v0.02.tar.gz
tar xf speech_commands_v0.02.tar.gz
mv speech_commands_v0.02 /tmp/speech_commands_v0.02
rm speech_commands_v0.02.tar.gz
cd -
```

2. Instead of converting the wave files by hand and manually picking files to use, the script `gen_micro_speech_files.sh` can do that for you using the following line of code:

```
mkdir -p output/micro_speech
rm -f output/micro_speech/* # Remove old files
./gen_micro_speech_files.sh /tmp/micro_speech_dataset ./output/micro_speech yes,no 5
```

*Short Manual:* `Usage: ./gen_micro_speech_files.sh [DATASET_DIR] [OUTPUT_DIR] [COMMANDS] [COUNT]`

## Setup SD-Card

Copy the `micro_speech` directory either from the `media/output/` directory or from where you extracted the contents of [`sd_card.zip`](https://raw.githubusercontent.com/PhilippvK/stm32-tflm-demos/master/media/sd_card.zip) to directory to the root directory of the SD card.


## Run the Program

Up to 16 `*.wav` files found in the `micro_speech` directory on the SD-Card are played back via the headphone jack and feed into the Neural Network. The current 1 second-long input sample changes every 3-5 seconds.

**Warning:** The network performs especially bad if the current sample changes, as the audio player has to be re-initialized to fetch a new wave file from the external media.

The name of the currently played file is displayed on the touchscreen. And all files found when reading the directory are printed on UART before the network starts.

## Known Issues

 - As mentioned before, the transitions between samples is quite buggy and still needs some optimazions
 - Feeding silent wave data does not result in `silence` beeing detected. Maybe a Volume-Normalization problem?