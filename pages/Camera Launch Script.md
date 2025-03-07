tags:: [[Script]]
description:: Launches IP cameras with Gstreamer
file:: ![launch_cameras.sh](../assets/scripts/launch_cameras.sh)

- ## Dependencies
	- `gst-launch-1.0` [instructions](https://gstreamer.freedesktop.org/documentation/installing/on-linux.html)
	- `python3`
- ## Usage
	- ```bash
	  ./launch_cameras.sh [num] ...
	  ```
	- `launch_cameras.sh` can be invoked with one or more numbers. It will attempt to launch a Gstreamer window streaming from `192.168.1.$num` for each of the numbers you provide.
-