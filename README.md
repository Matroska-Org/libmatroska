# libmatroska
a C++ libary to parse and create Matroska files

# Building and installing

## Building and installing the library

libmatroska is based on `cmake`. It requires a C++ compiler as well as
[libebml](https://github.com/Matroska-Org/libebml). This means that
the normal build process consists of the usual steps:

1. Create a build directory: `mkdir build ; cd build`
2. Generate the make file: `cmake ..`
3. Compilation: `make`
4. Installation (run this as root): `make install`

## Customizing what's build with options

By default only a static library is built.

This library supports the usual `cmake` options for specifying
installation paths (e.g. `-DCMAKE_INSTALL_PREFIX=/opt/libmatroska`). The
following additional `cmake` options are supported:

* `-Debml_DIR=/path/to/libebml` — if `libebml` was installed in a
  non-default location, you have to tell `cmake` where to find
  it. Point this variable to the directory containing the
  `EbmlConfig.cmake` file.
* `-DDISABLE_PKGCONFIG=YES` — don't generate and install the
  `libebml.pc` package configuration module for `pkg-config`
* `-DDISABLE_CMAKE_CONFIG=YES` — don't generate and install the
  package configuration module for `cmake`
* `-DBUILD_SHARED_LIBS=YES` — build the shared library instead of the
  static one (default: no)

## Code of conduct

Please note that this project is released with a [Contributor Code of Conduct](CODE_OF_CONDUCT.md). By participating in this project you agree to abide by its terms.
