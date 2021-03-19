# Raspberry PICO Library template
> This template is to create pico libraries ONLY for project/programms see my `pico-template` repo

*This project uses conventional commits and the `cz` command line utility*

## Setup

[here](SETUP.md)

## Usage

To use the compiled library you have 2 options

### Using the `.a` file

This uses a fixed version

1. Download the latest precompiled `libmylib.a` from github releases
2. Place it inside a `libs` folder in your project
3. use `find_library(my_external_lib mylib libs)`
   1. `libs` must be the name of the folder containing the `a` file
   2. `mylib` must be the name bevore the `.a` EXCLUDING the `lib` prefix
   3. `my_external_lib` is an custom name for later use choose whatever you feel like
4. Use `my_external_lib` in `target_link_libraries(...)`

### Sourcecode inclusion

This version can easily be changed with `git checkout <version>`

1. Clone the repo
2. Add `add_subdirectory(/path/to/my/lib)` (the path can also be relative)
3. Use `mylib` in `link_target_link_libraries(...)`



## Commands

| Command | Description |
|:--------|:------------|
| `compile.sh` | compiles the library and the example |
|`flash.sh` | compiles & flashes the example to the pico using *picotool* |
| `rebuild.sh` | builds the project from ground up (can fix some cmake weirdos sometimes) |

## Project Structure



### WSL (For use with **CLion**)
* `SETTINGS > Build, Execution, Deployment > CMake > Debug`
  * Environment: *PICO_SDK_PATH=/lib/mcu/pico*

### Code

- `src` : Sourcecode for the library
  - `mylib` : A folder to later distinguish you lib from others, rename to whatever suitable
    - `*.cpp/*.h` your cpp/c sourcecode
- `settings.cmake` : Change project build settings, include libraries and rename the project
- `out` : contains the binaries after compiling
  - `lib<name>.a` the compiled library
  - `<examplename>.uf2` the compiled example drag and drop flash file for the pico

### Adding new Sourcecode
You have to add each sourcefile individualy (CLion does it for you). This is due to raspis decition to use cmake

#### Lib
1. Add the files info `src/<libname>/`
2. Add them to `src/CMakeList.txt`
```cmake
add_library(${lib_name}
        mylib/foo.cpp
        mylib/foo.h
        <newfiles (h/cpp/c)>
)
```
#### Example
1. Add the files to `example/`
2. Add them to `example/CMakeList.txt`
```cmake
add_executable(${example_name}
    main.cpp
    <newfiles(cpp/c/h)>
)
```

### Rename you library
1. Change the `lib_name` in `settings.cmake` to whatever you like
2. (optional) it might be a good idea to adapt the foldername of the headers too
    1. rename `src/<old lib name>/` to `src/<new lib name>/`
