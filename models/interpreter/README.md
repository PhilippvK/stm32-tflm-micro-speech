## Interpreter Models

The models here are the result of `xxd -i model.tflite > model.cc` from the Colab Notebook. To deploy them on a microcontroller, there are two options:

1. Copy only the array data and its size to `Src/model_data.cc` keeping the `const` modifier in the declaration
2. Copy `model.cc` to `Src/model_data.cc` and update it to include the following:
  - `extern const` in front of the array datatype to make sure it will not consume any RAM.
  - At the top of the file:
  ```
  #include "model_data.h"
  ```

