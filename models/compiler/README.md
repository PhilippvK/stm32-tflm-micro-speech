## Compiler Models

Find out more about the compiler [HERE](https://github.com/tum-ei-eda/tflite_micro_compiler)!

The following commands were used to generate the compiler models:

```
compiler other/model.tflite compiler/offline_model.cc hello_world_
mv compiler/offline_model.cc.h compiler/offline_model.h
```

In the end, replace `Src/offline_model.cc/h` with the generated files! 
