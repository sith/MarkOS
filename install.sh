#!/usr/bin/env bash

rm -rf ~/workspace/myLibs/MarkOS_*
cd cmake-build-debug/common
make install
cd  ../os/
make install