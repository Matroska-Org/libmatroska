# libmatroska
a C++ libary to parse and create Matroska files

# Building and installing

## Building a released version

libmatroska is based on autoconf and automake. It requires a C++
compiler as well as [libebml](https://github.com/Matroska-Org/libebml)
and `pkg-config`. Being an autoconf-based project means that the
normal build process consists of the usual three steps:

1. Configuration: `./configure`
2. Building: `make`
3. Installation (run this as root): `make install`

## Building from git

If you're building from git you must have the GNU autotools
(`autoconf`, `automake`, `libtoolize`) installed. Then run the
following two commands:

1. `libtoolize`
2. `autoreconf -vi`

Afterwards continue with the steps listed for building a released
version.
