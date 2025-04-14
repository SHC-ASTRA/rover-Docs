tags:: [[General]]
description:: Exporting `mbtiles` from [OpenStreetMap Exports](https://download.geofabrik.de/) `pbf` 

- The following describes how to take data downloaded from [OpenStreetMap Exports](https://download.geofabrik.de/) provided by <ins>geofabrik.de</ins>

- ## Requirements
    - Docker Engine ([installation](https://docs.docker.com/engine/install/))is required in order to copmlete this process

- ## Instructions
    - Download a `.pbf` record, such as [utah-latest.osm.pbf](https://download.geofabrik.de/north-america/us/utah-latest.osm.pbf)
    - `docker pull` the `tilemaker:master` image from `ghcr.io/systemed/tilemaker:master`
    - Locate and open a terminal in the directory in which you downloaded the `.pbf` directory
    - Run the following `docker` command: `docker run -it --rm -v $(pwd):/data ghcr.io/systemed/tilemaker:master --input=/data/DOWNLOADED_FILE.osm.pbf --output=/data/DOWNLOADED_FILE.mbtiles`

- ## Further Configuration
    - See the [documentation regarding configuration](https://github.com/systemed/tilemaker/blob/master/docs/CONFIGURATION.md) 
    - There are many different possible configuration files that are possible to be used
    - Layers can be configured to display at different zoom heights
        - I am currently unsure how one goes about finding which layers exist within the `.pbf` file in order to modify the exported `.mbtiles` content