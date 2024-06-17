# Raspberry Pi Setup
The script provided is to setup a new Raspberry Pi to be used for modules on the rover. The script does a series of setups and installations. **Internet access is required on the device prior to executing the script**

### Actions //What the script does
- Uninstall/Disable cloud-init
- Disable X service to prevent waiting for internet on boot
- Disable X service to prevent delaying boot
- Configure static IP for Ethernet interface **This should be changed in the config before running**
- Configure hostname **This should be changed in the config before running**
- 


# Pre-Requisites //Things that need to happen before you can run the script sucessfully
**Update the config file with necessary values before running**
Hardware: Raspberry Pi 4B+ (Not tested on other boards)
OS: Linux, Ubuntu **server** **22.04** (stable LTS linux version currently supported for ROS2 Humble)
Internet: YES


