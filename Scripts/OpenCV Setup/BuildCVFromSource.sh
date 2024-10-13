#!/bin/bash
#Prep Dependencies
sudo apt update && sudo apt install -y cmake g++ wget unzip
#Download the archive files and unzip them
wget -O opencv.zip https://github.com/opencv/opencv/archive/4.x.zip
wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/4.x.zip
unzip opencv.zip
unzip opencv_contrib.zip
#Make build directory and move into it.
mkdir -p build && cd build
#Build
cmake -DOPENCV_EXTRA_MODULES_PATH=../opencv_contrib-4.x/modules ../opencv-4.x
cmake --build .
sudo make install
#Remove zipped archives to save space
rm opencv.zip && rm opencv_contrib.zip

