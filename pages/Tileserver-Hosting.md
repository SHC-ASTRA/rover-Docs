tags:: [[General]]
description:: Using an exported `.mbtiles` to configure and run a tileserver 

- The following describes how to take data exported from a `.pbf` file to host a tileserver for web connections

- ## Requirements
    - Docker Engine ([installation](https://docs.docker.com/engine/install/)) is required in order to complete this process

- ## Instructions
    - Perform the instructions outlined regarding `.pbf` files
    - `docker pull` the `maptiler/tileserver-gl` image
    - Locate and open a terminal in the directory in which you exported the `.mbtiles`
    - Run the following `docker` command: `docker run -it --rm -v $(pwd):/data --network host maptiler/tileserver-gl --file EXPORTED_FILE.mbtiles`

- ## Further Configuration
    - There are options for further advanced configuration using `style.json` files to configure the color and multiple `.mbtiles` files and layers