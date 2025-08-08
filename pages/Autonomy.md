tags:: [[Documentation]] 
description:: This project is designed for the 2024 URC competition, specifically for 
the autonomy portion. It was made by the UAH ASTRA Software team, with 
the hopes to build a foundation for future challenges as well.

- # Table of Contents
	- 1. Title
	- 2. Table of Contents
	- 3. Requirements
		- ROS2 Humble
		- Colcon
		- OpenCV
		- RealSense
	- 4. Hardware Requirements
	- 5. Recommended Programs
	- 6. How to Use
	- 7. Common Problems/Troubleshooting
	- 8. Major To-Do Items
	- 9. Author
	- 10Maintainer
	  
	  # Requirements 
	  Before downloading anything, it is a good idea to make sure your system is up to date and that all software you are using is as well. If you are on Ubuntu/Debian, the following commands will do so. 
	  
	  All commands in this document will be for Ubuntu.
	  
	  ```
	  sudo apt-get install && sudo apt-get upgrade
	  ```
	  
	  ## ROS2 Humble
	  We use ROS2 (Robot Operating System) Humble, and plan on using that until support for it expires. If you are not using Ubuntu/Debian, go to the [ROS2 Website](https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debians.html) to know how to install ROS2, otherwise follow along.
	  
	  The first step is to make sure you have Ubuntu Universe Repository, which is necesary for ROS.
	  
	  ```
	  sudo apt install software-properties-common
	  sudo add-apt-repository universe
	  ```
	  
	  After those are installed, you need to add the ROS2 GPG key through apt.
	  
	  ```
	  sudo apt update && sudo apt install curl -y
	  sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
	  ```
	  
	  Then add that repository to your sources list. 
	  
	  ```
	  echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
	  ```
	  
	  Now to actually install ROS2 Humble
	  
	  ```
	  sudo apt update
	  sudo apt upgrade
	  sudo apt install ros-humble-desktop
	  ```
	  
	  Now ROS2 has been downloaded. Remember, to actually use ROS in a terminal, you have to source it with `source /opt/ros/humble/setup.bash`. You can also add this line to the bottom of your .bashrc file if you want to always have ros2 sourced in your terminal.
	  
	  ## Colcon
	  Colcon is used for building ros2 packages, and is quick to install. The following command is all that you need if you are running Ubuntu/Debian, otherwise check the [ROS2 Website](https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debians.html) for information on how to download.
	  
	  ```
	  sudo apt install python3-colcon-common-extensions
	  ```
	  
	  ## OpenCV
	  OpenCV is used for ARUCO detection and other small but complicated tasks. These steps will take a while, so make sure your device has good internet and is plugged in before starting. This informatin is on the [OpenCV Website](https://docs.opencv.org/4.x/d7/d9f/tutorial_linux_install.html), however I found the documentation formatting poor, 
	  
	  These are the prerequisites for this process and for OpenCV. 
	  
	  ```
	  sudo apt update && sudo apt install -y cmake g++ wget unzip
	  ```
	  
	  You need to then download the source files, and unpack them. 
	  
	  ```
	  wget -O opencv.zip https://github.com/opencv/opencv/archive/4.x.zip
	  wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/4.x.zip
	  unzip opencv.zip
	  unzip opencv_contrib.zip
	  ```
	  
	  Create a build directory and switch into it
	  
	  ```
	  mkdir -p build && cd build
	  ```
	  
	  Configure the build
	  
	  ```
	  cmake -DOPENCV_EXTRA_MODULES_PATH=../opencv_contrib-4.x/modules ../opencv-4.x
	  ```
	  
	  Then build
	  
	  ```
	  cmake --build .
	  ```
	  
	  Finally, after that has finished, install
	  
	  ```
	  sudo make install
	  ```
	  
	  ## RealSense
	  Using the D435i camera lets us use many libaries, but first requires installing dependencies. First is [Librealsense](https://github.com/IntelRealSense/realsense-ros libaries, which are installed easily enough.)
	  
	  ```
	  sudo apt install ros-humble-librealsense2*
	  ```
	  
	  Then you have to make a ROS2 Wrapper for it. This requires downloading the package into ros2_ws/src. 
	  
	  # Hardware Requirements
	  Needs a camera to run object detection or AruCo. If running realsense-ros, also requires a RealSense Camera(435i is what we used). Other than that, just a computer with software requirements.
	  
	  # Recommended Programs
	  
	  ## VSCode
	  VSCode is a wonderful program. I used it to make this project and recommend anyone else working on it use it as well.
	  
	  ```
	  sudo snap install --classic code
	  ```
	  
	  # How to Use
	  The purpose of this program is to, as stated above, run the ASTRA Rover autonomously within the [URC](https://urc.marssociety.org/home/about-urc) guidelines for the autonomous mission, made first for the 2024 mission, but modular to fit future missions.
	  
	  Before running this program, you will have to build it, like all ROS packages. Once downloaded, navigate to the `/rover-Autonomy/` directory, which should contain this README.md file and one directory called `ros2_ws`. Navigate to this directory, which will contain a `src` directory and a png file. Then use the following command to build. 
	  
	  ```
	  colcon build
	  ```
	  
	  There are two parts to running this project, one is to run the server, and the other is to run the client. Once the server is started, you do not need to touch it again. The client, however, is what is used to communicate with the server. A new command requires a new client.
	  
	  The Server is run with the command
	  
	  ```
	  ros2 run actions_cpp navigate_rover_server
	  ```
	  
	  The Client is run with the command
	  
	  ```
	  ros2 run actions_cpp navigate_rover_client
	  ```
	  
	  Once the client has been started, it will ask you what input type you would like to use. This is the type of action you wish the rover to perform, inputing a number. The options are listed below. After the input type, there will be two more inputs, which are parameters for the function, which are listed below as well in the format (First input, Second input). 
	  
	  1. Go to GPS Point
	     - (Target Latitude, Target Longitude)
	  2. Go and search around point for ARUCO
	     - (Target Latitude, Target Longitude)
	  3. GO and search around point for objects
	     - (Target Latitude, Target Longitude)
	  4. DEBUG 1
	     - Same as 1, but without looping, for test
	     - (Target Latitude, Target Longitude)
	  5. DEBUG 2
	     - Drives forward a small amount
	     - Does nothing
	  6. DEBUG 3
	     - Search Pattern
	  7. DEBUG 4
	     - Aruco Testing
	  8. DEBUG 5
	     - Object Detection Testing
	     - Does nothing currently
	  9. DEBUG 6
	     - Does nothing, empty
	  10. INTERNAL 1
	     - When Aruco is detected by aruco detection node, it sends this goal. 
	  11. INTERNAL 2
	     - When object is detected by obj detect node, it sends this goal.
	  
	  # Common Problems/Troubleshooting
	  
	  ## Open CV exception
	  If you get the error "install libgtk2.0-dev and pkg-config" when using Aruco detection, do the following from the home directory, assuming you followed above instructions for downloading OpenCV. Otherwise, instead of going to build directory, go to wherever you installed OpenCV.
	  
	  '''
	  sudo apt install libgtk2.0-dev pkg-config
	  cd build
	  mkdir Release
	  cd Release
	  cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D WITH_TBB=ON -D BUILD_NEW_PYTHON_SUPPORT=ON -D WITH_V4L=ON -D INSTALL_C_EXAMPLES=ON -D INSTALL_PYTHON_EXAMPLES=ON -D BUILD_EXAMPLES=ON -D WITH_QT=ON -D WITH_GTK=ON -D WITH_OPENGL=ON ..
	  cd ..
	  make
	  sudo make install
	  '''
	  
	  # Major To-Do
	  
	  # Author
	  
	  Name: Daegan Brown
	  
	  Email: daeganbrown03@gmail.com
	  
	  Phone: 423-475-4384
	  
	  # Maintainer
	  
	  Name: Daegan Brown
	  
	  Email: daeganbrown03@gmail.com
	  
	  Phone: 423-475-4384
	  ```