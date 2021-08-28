# libdogbarfcal

This is a small and opionated c library to calculate food consumption of a dog based on barf.

## How to build

To build the project you can run:

```
cmake -Bbuild -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_EXPORT_PACKAGE_REGISTRY=1
cmake --build build
cd example
cmake -Bbuild -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_EXPORT_PACKAGE_REGISTRY=1
cmake --build build
```

A more detailed description will follow.

