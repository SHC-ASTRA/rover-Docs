tags:: [[Documentation]] 
description:: Basestation documentation

- # **basestation-game**
- ## About
	- Description of the installation and use of
- # Table of Contents
  
  1. Title
  
  2. Table of Contents
  
  3. Software Requirements
  
    1. ROS2 Humble (If necessary for the repo)
  
    2. Static IP Address
  
  4. Hardware Requirements
  
  5. Recommended Programs
  
  6. How to Use
  
  7. Common Problems/Troubleshooting
  
  8. Major To-Do Items
  
  9. Author(s) 
  
  10. Maintainer(s)
- # Software Requirements
- Since July/August of 2025, ASTRA uses NixOS.  
  
  A functioning NixOS installation is assumed.
- ## ROS2 Humble
  
  We use ROS2(Robot Operating System) Humble, and plan on using that until support for it expires. 
  
  
  
  To install ROS2, run the following command in your /etc/nixos folder:
  ```nix
  nix flake init --template github:lopsided98/nix-ros-overlay
  ```
- ## Godot
- We use the Godot game engine to develop the rover interaction system.
-
- To install Godot, add the following package to your pkgs array / packages.nix config file:
- ```nix
  godot-mono
  ```
-
- # Hardware Requirements 
  
  A Functioning Computer.
- # Recommended Programs
- ## VSCode
  
  VSCode is a wonderful program. I used it to make this project and recommend anyone else working on it use it as well. 
  
  To install VSCode, add the following package to your pkgs array / packages.nix config file:
  ```nix
  vscode-fhs
  ```
  
  Alternatively, use a flake to install home-manager, and add to your home.nix:
  ```nix
  vscode.enable = true;
  ```
- # How to Use
  
  The purpose of this program is to, as stated above, run the ASTRA Rover's Base-Station. At the current moment however, there is no product to run.
  
  
  
  **INPUT INSTRUCTIONS FOR HOW TO RUN**
- you don't
- # Common Problems/Troubleshooting
  Ain't got no problems :sunglasses:
- # Major To-Do Items
  
    - Major to-do 1
- # Author(s)
  
  
  
  |Name| Email |
  | Roald Schaum | rks0015@uah.edu |
- # Maintainer(s)
  
  
  
  
  
  |Name| Email |
  | Roald Schaum | rks0015@uah.edu, roaldschaum2019@gmail.com |