#!/bin/bash
#
# Copyright (C) 2013-2018 Draios Inc dba Sysdig.
#
# This file is part of sysdig .
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
set -e

arch="$(uname -i)"

if [[ "$arch" == "s390x" ]] || [[ "$arch" == "ppc64le" ]]; then
	export CC="gcc-7"
	export CXX="g++-7"
else
	export CC="gcc-4.8"
	export CXX="g++-4.8"
fi
wget https://mirrors.edge.kernel.org/pub/linux/kernel/v5.x/linux-5.4.28.tar.gz
tar -xzf linux-5.4.28.tar.gz
export KERNELDIR=`pwd`/linux-5.4.28
wget https://github.com/Kitware/CMake/releases/download/v3.16.4/cmake-3.16.4.tar.gz
tar -xzf cmake-3.16.4.tar.gz
cd cmake-3.16.4
./bootstrap --prefix=/usr
make
sudo make install
cd ..
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=$BUILD_TYPE
make VERBOSE=1
make package
make run-unit-tests
cd ..
test/sysdig_trace_regression.sh build/userspace/sysdig/sysdig build/userspace/sysdig/chisels $TRAVIS_BRANCH
