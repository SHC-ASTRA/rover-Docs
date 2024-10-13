<hr> The ROC-RK3328-CC, also known as the Libre Renegade, is a single board computer used by ASTRA in the past and often for two month projects. Setting up a new one can be a pain though, so I made this guide. <br>

## Table of Contents <hr>

1. Title and Introduction
2. Table of Contents
3. Requirements 
4. Step 1: Setting up the micro-SD card
5. Step 2: Setting up the Libre
6. Step 3: Using the Libre
7. Known Issues
## Requirements <hr>
1. A ROC-RK3328-CC single board computer. Duh. 
2. A micro-SD card to hold the OS of the Libre. 
3. A laptop or computer running Linux, preferably Ubuntu, with a way to read micro-SD cards
4. An internet connection. 
## Step 1: Flashing Ubuntu to the micro-SD card <hr>
Download the image file for the Operating system you want [here](https://distro.libre.computer/ci/ubuntu/22.04/), making sure to select one for the right board. I recommend the [server version](https://distro.libre.computer/ci/ubuntu/22.04/ubuntu-22.04.3-preinstalled-server-arm64%2Broc-rk3328-cc.img.xz) for ease of use. 
Unzip the image file. Navigate to the directory you downloaded it to, and then run the command below. Note that if you don't have xz-utils installed, you will need to do that with `sudo apt-get install xz-utils`. You will also need to change the file name below if you used a version besides the server install. 
```
unxz ubuntu-22.04.3-preinstalled-server-arm64+roc-rk3328-cc.img.xz
```
Now you need to flash this .img file to the micro-SD card. On a computer running Ubuntu, this is incredibly easy to do. Simply insert whatever SD reader you are using, and then open the Ubuntu disc manager. You can find it by searching for "Disks" on your device, then once it is open, click on the micro-SD card from the list of attached disks. Click the three vertical dots on the top right, next to the minimize button, and click "Restore Disk Image..." and select the image file you downloaded above. When that finishes, the SD card is ready. If you don't have Ubuntu, there is a way to do this via command line, and I wish you the best of luck finding those ways. 
## Step 2: Setting up the Libre for use <hr>
Insert the micro-SD card into the Libre, and power it using a micro-USB cord from a 5 volt power supply. 
Hook up a keyboard to one of the USB ports and a monitor to the HDMI port. I had trouble running a Samsung monitor off the Libre, which is not unheard of on Libre's, so if you can, don't use a Samsung monitor.
After the startup text scrawl is done, it will prompt you for a username. The default is "Ubuntu" which is also the default password. It will prompt you to change both of those immediately, which I highly recommend, for the sake of security, and my ever-growing paranoia. 
Once you are in, you need to set a static IP address to ssh into the device. This can be done with the command below: 
```
sudo ip addr add <192.168.1.x>/8 dev eth0
```
with the \<192.168.1.x> being the static IP address you want to set it to, replacing the x, such as 192.168.1.1, etc. However, even after running that command, a reboot will reset the IP address. So what you need to do is put the command in your crontab file. Simply run the command: 
```
sudo crontab -e
```
to open the crontab file, or create one if it doesn't exist. If prompted for which text editor to use, select whichever you prefer, or if you are unfamiliar with each, select nano.
At the first available line, type `@reboot sudo ip addr add <192.168.1.x>/8 dev eth0`. This insures that the command will be run upon reboot, meaning every time the Libre boots, it will set an IP, so you will always be able to connect to it. Now save the file and exit. If using nano, hit ctrl + x, hit y, and then hit enter. 
Now the libre is fully set up and ready to use. 
## Step 3: Using the Libre <hr>
Now that it is setup, you can access the Libre via ssh. 
Simply connect your device to the Libre with an Ethernet cable, and then use the command below:
```
ssh <username>@<192.168.1.x>
```
Replacing \<username> with the username you setup, and the \<192.168.1.x> with whatever IP address you gave the Libre. To connect, you might have to set up your computer IPv4 manually. To do this on Ubuntu, simply click on the gear icon in setting next to wired connection, go over to the IPv4 tab, click manual, and then fill out "192.168.1.y" for the IP address, with y being different than x from before, "255.255.255.0" for the netmask, and "192.168.1.0" for the gateway. 

## Known Issues <hr>
- Samsung monitors sometimes do not connect to Libre's
