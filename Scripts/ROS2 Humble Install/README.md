# ROS2 Humble Install Script
The script provided is to install ROS2 humble and all its dependencies.

### Actions //What the script does
- Installs ROS2 Humble: https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debians.html
    - Ensure locale is set to UTF8
    - Apt Install software-properties-common
    - add-apt-repository universe
    - Add ROS2 Hubmble repo to the source list
    - Apt update & upgrade
    - Apt Install ROS-Humble-Desktop (To get all tools and packages)
    - Source Humble in the ~/.bashrc
    - Source Humble in the current terminal
- Installs Colcon: https://colcon.readthedocs.io/en/released/user/installation.html
    - Add the colcon repo to the source list
    - Apt Install colcon 


# Pre-Requisites //Things that need to happen before you can run the script sucessfully
Hardware: N/A
OS: Linux, Ubuntu (Desktop *or* Server) **22.04** (stable LTS linux version currently supported for ROS2 Humble)
Internet: YES
