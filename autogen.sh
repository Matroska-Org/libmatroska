#!/bin/bash

set -e

aclocal
autoheader
libtoolize --copy
automake --add-missing --copy
autoconf
