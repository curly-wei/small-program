# Opencv with cmake and dynamic libs for test </br> --How to build this project

## Check dependencies and dol dependencies configure file

There are **required** dependencies and its version for this project

* opencv @ 4.0

File of dol dependencies configure put following directories:

``` Bash
./src/CMakeModulesForDol/ConfigDependencies/
```

please check these dol dependencies configure file

(The path where the dependencies you installed are located)

before build.

It is very important!

Don't forget!

## Before build - change directories for build

Please change directories folders for your requirement:

``` Bash
#on the debug mode
./opencv_dll_cmake/build/debug
```

``` Bash
#on the release mode
./opencv_dll_cmake/build/release
```

Above command is executed by bash:

``` Bash
#debug mode
cd ./build/debug
```

``` Bash
#release mode
cd ./build/release
```

Makesure your $PWD.

If $PWD is correct (./build/debug or ./build/debug as per your requirements)

Go to start to build this project (see section of **Build**).

## Build

Result and files after build all are in the following folder:

``` Bash
#binaries files
/path/to/top_bin_build/output/bin

#libs files
/path/to/top_bin_build/output/lib

# /path/to/top_bin_build/output/bin
# can solved as
# ./build/debug/output/bin
# or
# ./build/release/output/bin
```

### Windows platform

#### debug mode [Windows]

``` Bash
cmake -G "Visual Studio 15 2017" -A x64 -DCMAKE_BUILD_TYPE=Debug ../../src
cmake --build . --config Debug
```

or

``` Bash
cmake -G "Visual Studio 15 2017" -A x64 -DCMAKE_BUILD_TYPE=Debug ../../src
MSBuild.exe dol_core.sln /property:Configuration=Debug /property:Platform=x64
```

#### release mode [Windows]

``` Bash
cmake -G "Visual Studio 15 2017" -A x64 -DCMAKE_BUILD_TYPE=Release ../../src
cmake --build . --config Release
```

or

``` Bash
cmake -G "Visual Studio 15 2017" -A x64 -DCMAKE_BUILD_TYPE=Debug ../../src
MSBuild.exe dol_core.sln /property:Configuration=Release /property:Platform=x64
```

### Linux(Unix) platform

#### debug mode [Linux(Unix)]

``` Bash
cmake ../../src -DCMAKE_BUILD_TYPE=Debug
cmake --build . --config Debug
```

#### release mode [Linux(Unix)]

``` Bash
cmake ../../src -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release
```

## Install (on the unix)

First, install mode must be after **`release build`**

After release build,

execute:

``` Bash
sudo make install
```

After install,

The executable bin-files located on `/usr/bin/`

The lib-files located on `/usr/lib/`

The resource-files located on `/usr/share/dol_core/`

The header-files for this project located on `/usr/include/dol_core/`
