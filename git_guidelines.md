# Git Guidelines	
This document outlines the procedures and processes the ASTRA team uses for GitHub. This guideline should be followed for all members of the team and updated when necessary.

## Repositories
### Creating New Repositories
Currently: a repo exists per-module and code for each module should be stored within the repository. New repos should only be created when their purpose extends beyond the scope of existing repos. 
New repos should follow the standardized layout outlined below.

### Standard Repository Structure
Repos should all follow a standard layout as follows:

 - **README**
	 - This should follow the template README outlined in the rover-Docs repo, templated folder
 - **/{module_name}_ws**
	 - Examples: arm_ws, core_ws, biosensor_ws
	 - This directory is the ROS2 workspace for the current repo
	 - Usually there will be one workspace per-repo and one module per-repo in which case simply replace {module_name} with the name of the rover module
	 - In other cases, {module_name} can be set at the descretion of the author
 - **/{module_name}_{MCU}_embedded**
	 - Examples: arm_main_embedded, arm_endEffector_embedded
	 - This directory is the PlatformIO project for the give microcontroller
	 - Same here, {module_name} should be replaced with the respective rover module if applicable
	 - In the case that there are multiple MCUs on a given module or PlatformIO projects in a given repo, use: **/{module_name}_{MCU}_embedded**. {MCU} should be replaced by a specification of which MCU on the module (only if there are multiple)

### Delete / Remove Repository 
Repos generally shouldn't be deleted. In almost all cases it's better to archive the repo so that it is labeled as such and cannot but updated but can still be read-only. 

## Branches
All new developments should occur on branches within repositories. 

### Creating Branches
Create a branch when you're adding a new feature or fixing a bug. Name the branch *appropriately* for its purpose. 

### Merging Branches / Pull Requests
Once work is completed on a branch a pull request should be made to merge the branch with the repo's main branch. There should be an overview of the pull request by the software team at a meeting before the merge pull request is completed. This should help catch bugs, hold people accountable, and ensure everyone is on the same page as to the state of repos.

When making a pull request be sure to:
 - Name the pull request: Merge name_of_the_branch (all you should have to do is add the word "Merge")
 - Add a meaningful description
 - Assign reviewers (subteam lead(s) and other relevant people)
 - Assign yourself and other developers as Assignees
 - Assign the project as "SW Tasking"
 - Create an issue under "Pending Review" for the merge. (Check, but this should be done automatically)

## Submodules
### Adding a submodule to your repo
To add a submodule to your repo:
 - cd to the location where you want the submodule in your repo
 - run ``git submodule add SUBMODULE_GIT_SSH_URL``

### Cloning
When cloning repositories that have submodules you'll need to do recursive cloning to get the submodule downloaded. You must also ensure you update the submodule and test your code again before pushing if changes were made to the submodule. It's good to update the submodules with ``git subup`` from time to time even if the repo you're working in has no changes. 

Example:
```
//To clone recursively simply add the --recurse argument
$ git clone --recurse SSH_REPO_URL_HERE
```

### Updating the submodules
When updating submodules you just run ``git subup`` to update all submodules. **(See git_setup.md for details on how to get the ``git subup`` command)**
Alternatively you can run the update command yourself:
``git submodule deinit -f --all && git submodule init && git submodule update --remote``


## Other
### Issue Tracking
 Issue tracking is a new introduction for the URC 2025 development cycle and will be used in the future to track bugs, changes, tasks, & planning for the software subteam. Issues should always be properly labeled with an assignee, target date, and priority level. 

*The issue tracker can be found under "projects" within the "SW Tasking" project.*

Issues, once completed by any member, should be moved only to the "Pending Review" column until a group or subteam lead(s) review determines that the issue is completed. After a successful review a given issue can be moved to "Done" in which case the issue should be closed if that's not done automatically. Closed issues should be automatically archived 2 weeks after being marked as closed to avoid clutter.
 

### Teams & Permissions
All members of the software team on a given year should be added to a new team for that year. The team will be named "SW URC 202X" for the URC development year. The team for each year will be added as a subset of "ASTRA Software Subteam" team so each years' team inherits the permissions of the "ASTRA Software Subteam" parent team.

All  members should have permission to create, edit, & branch repos. All members, admins included, should be required to undergo review of any pull request before merges are completed. 

Delete permissions should be reserved for administrators of the git (i.e. subteam/team lead(s)). In most cases things should be **archived** instead of deleted so that they can be referenced at any time after they're no longer in use. 
