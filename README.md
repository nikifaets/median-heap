# median-heap
Data structure that supports logarithmic element insertion and constant median retrieval.

## Download and run

Clone and setup googletest submodules:
```sh
git clone https://github.com/nikifaets/median-heap
cd median-heap
git submodule init
git submodule update
```


Build:

```sh
mkdir build; cd build
cmake ..
make
```

Run tests:

```sh
./test/MedianHeapTests
```

Tested on Arch Linux with gcc c++14 and CMake 3.14.
