# ROS2-TSN

## Commands

```bash
# Source Environment
source /opt/omnetpp/setenv
# To start the OMNeT++ IDE
omnetpp
```

# Initial Setup Configurations

 1. Within INET choose your workspace as the /TSN_SIM directory
 2. Install the INET library within this directory
 3. Right click and build both the INET project and the ROS_TSN_Bridge project
 4. Right Click on ROS2_TSN_Bridge -> Properties -> Project References -> Check inet
 5. Right Click on ROS2_TSN_Bridge -> C/C++ General -> Paths and Symbols -> Includes -> GNU C++ -> Add -> Workspace -> Choose /inet4.5/src/ Check is a workspace path -> Apply and Close -> Right Click and Build project again


## Helpful tips

1. Display: To port the display from your docker container to the display on your host machine, it's highly recommended to use X410 which can be downloaded from the Microsoft Store.