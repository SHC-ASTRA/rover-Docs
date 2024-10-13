# *Repository Name*
# UAH ASTRA 

This project is designed for the *year* URC competition, specifically for the *submodule* portion. It was made by the UAH ASTRA *subteam* team, with the hopes to build a foundation for future challenges as well. 

# Table of Contents
1. Title
2. Table of Contents
3. Software Requirements
   - ROS2 Humble
   - Colcon
4. Hardware Requirements
5. Recommended Programs
6. How to Use
7. Common Problems/Troubleshooting
8. Major To-Do Items
9. Author 
10. Maintainer

# Software Requirements 
Before downloading anything, it is a good idea to make sure your system is up to date and that all software you are using is as well. If you are on Ubuntu/Debian, the following commands will do so. 

All commands in this document will be for Ubuntu.

```
sudo apt-get install && sudo apt-get upgrade
```

## ROS2 Humble
We use ROS2(Robot Operating System) Humble, and plan on using that until support for it expires. If you are not using Ubuntu/Debian, go to the [ROS2 Website](https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debians.html) to know how to install ROS2, otherwise follow along.

The first step is to make sure you have Ubuntu Universe Repository, which is neccesary for ROS.

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
## clucky_interfaces
Need this interface package for the action templates. This can be adjusted to your interface package, or take clucky_interfaces from [rover-Autonomy](https://github.com/SHC-ASTRA/rover-Autonomy) repo

# Hardware Requirements 
Functioning Computer.

# Recommended Programs

## VSCode
VSCode is a wonderful program. I used it to make this project and reccomend anyone else working on it use it as well. 

```
sudo snap install --classic code
```

# How to Use
The purpose of this program is to, as stated above, run the ASTRA Rover * PURPOSE*

*INPUT INSTRUCTIONS FOR HOW TO RUN*


# Common Problems/Troubleshooting

*Insert common Problems*

*solutions for common problesm*

# Major TO-Do Items


# Author

Name: 

Email: 

Phone: 

# Maintainer

Name: 

Email: 

Phone: 
