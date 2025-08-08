# *Repository Name*
- ## About
- Description for what the repository is for.
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
  Since July/August of 2025, ASTRA uses NixOS.
    
  A functioning NixOS installation is assumed.  
  
- ## ROS2 Humble
  We use ROS2(Robot Operating System) Humble, and plan on using that until support for it expires. 
  
  To install ROS2, run the following command in your /etc/nixos folder:
  ```nix
  nix flake init --template github:lopsided98/nix-ros-overlay
  ``` 
- ## Insert Headers/Descriptions/Brief tutorial for other required software items
- # Hardware Requirements 
  - A Functioning Computer.
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
  The purpose of this program is to, as stated above, run the ASTRA Rover * PURPOSE*
  
  *INPUT INSTRUCTIONS FOR HOW TO RUN*
- # Common Problems/Troubleshooting
  
  *Insert common Problems*
  
  *solutions for common problems*
- # Major To-Do Items
	- Major to-do 1
- # Author(s)
  
  |Name| Email |
  |--|--|
  | first_and_last_name | authors_email_for_contact |
- # Maintainer(s)
  
  
  |Name| Email |
  |--|--|
  | first_and_last_name | maintainers_email_for_contact |