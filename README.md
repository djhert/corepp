# CoreUtils++

CoreUtils++ is a toy project for a full reimplementation of the Coreutils for a POSIX system written in modern C++17.  The goal also being that the header files are also setup to be imported and available in any C++ application (more on this as it develops).

## Building

CoreUtils++ can be built as a single multi-call binary, or as a set of binaries for each tool.

CMake is required to build the application. 

```sh
$ cd corepp
$ mkdir build
$ cd build
$ cmake -DCORE_BUILD_TYPE=Single ..
- OR -
$ cmake -DCORE_BUILD_TYPE=Multi ..
```

The resulting binary (or binaries) will be available in `build/bin`

The current setup of this project is just a "proof of concept" and will be expanded upon later.  