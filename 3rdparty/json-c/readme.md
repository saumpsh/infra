# JSON-C 3rd Party library

## Steps to generate `json-c` libary and header files:

Clone repository

```bash
$ git clone https://github.com/json-c/json-c.git
$ cd json-c
```

### A. For Host machine (i.e. x86-64)

```bash
$ mkdir build_x86
$ cd build_x86
$ cmake -D CMAKE_INSTALL_PREFIX=~/Documents/json-c-install-x86 ..
$ make
$ make install
```


### B. For Host machine (i.e. arm64)

Ensure Cross toolchain for arm64 is installed in `/opt/`

```bash
$ wget https://developer.arm.com/-/media/Files/downloads/gnu-a/9.2-2019.12/binrel/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu.tar.xz

$ sudo tar -xvf gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu.tar.xz -C /opt
```

Create a toolchain file

```
# toolchain-aarch64.cmake

# the name of the target operating system
set(CMAKE_SYSTEM_NAME Linux)

# which C and C++ compiler to use
set(CMAKE_C_COMPILER /opt/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER /opt/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-g++)

# location of the target environment
set(CMAKE_FIND_ROOT_PATH /opt/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/aarch64-none-linux-gnu)

# adjust the default behavior of the FIND_XXX() commands:
# search for headers and libraries in the target environment,
# search for programs in the host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
```


```bash
$ mkdir build_arm64
$ cd build_arm64
$ cmake -D CMAKE_TOOLCHAIN_FILE=~/Documents/cmake-cross-compile/toolchain-aarch64.cmake -D CMAKE_INSTALL_PREFIX=~/Documents/json-c-install-arm64 ..
$ make
$ make install
```

### Integrate with Bazel

1. Copy install directory to Bazel directory and a build file 

```c
$ cp ~/Documents/json-c-install <path/to/bazel/workspace/3rdparty>
```

```py

cc_library(
    name = "json_c_headers",
    hdrs = glob(["include/json-c/*.h"]),
    includes = ["include"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "json_c_lib_arm",
    srcs = ["lib/aarch64/libjson-c.a"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "json_c_lib_x86_64",
    srcs = ["lib/x86_64/libjson-c.a"],
    visibility = ["//visibility:public"],
)
```

Following is the directory layout of the Bazel repository with the new library

```bash
3rdparty/json-c
├── BUILD
├── include
│   └── json-c
└── lib
    ├── aarch64
    └── x86_64
```

Note: At the time of writing the commit hash in master is `e3464a2ab4e0a7166543a178cb9f26c4cb3b9b61`

Reference: 
1. https://github.com/json-c/json-c
2. https://stackoverflow.com/questions/34984290/how-to-use-bazel-to-build-project-uses-opencv/35024014#35024014
3. https://stackoverflow.com/questions/46146441/building-a-cmake-library-within-a-bazel-project
