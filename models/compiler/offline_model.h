// This file is generated. Do not edit.
// Generated on: 21.10.2020 17:48:55

#ifndef mirco_speech_GEN_H
#define mirco_speech_GEN_H

#include "tensorflow/lite/c/common.h"

// Sets up the model with init and prepare steps.
TfLiteStatus mirco_speech_init();
// Returns the input tensor with the given index.
TfLiteTensor *mirco_speech_input(int index);
// Returns the output tensor with the given index.
TfLiteTensor *mirco_speech_output(int index);
// Runs inference for the model.
TfLiteStatus mirco_speech_invoke();

// Returns the number of input tensors.
inline size_t mirco_speech_inputs() {
  return 1;
}
// Returns the number of output tensors.
inline size_t mirco_speech_outputs() {
  return 1;
}

inline void *mirco_speech_input_ptr(int index) {
  return mirco_speech_input(index)->data.data;
}
inline size_t mirco_speech_input_size(int index) {
  return mirco_speech_input(index)->bytes;
}
inline int mirco_speech_input_dims_len(int index) {
  return mirco_speech_input(index)->dims->data[0];
}
inline int *mirco_speech_input_dims(int index) {
  return &mirco_speech_input(index)->dims->data[1];
}

inline void *mirco_speech_output_ptr(int index) {
  return mirco_speech_output(index)->data.data;
}
inline size_t mirco_speech_output_size(int index) {
  return mirco_speech_output(index)->bytes;
}
inline int mirco_speech_output_dims_len(int index) {
  return mirco_speech_output(index)->dims->data[0];
}
inline int *mirco_speech_output_dims(int index) {
  return &mirco_speech_output(index)->dims->data[1];
}

#endif
