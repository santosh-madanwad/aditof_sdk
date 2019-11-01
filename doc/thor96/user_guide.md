# Thor96 User guide

## Setting up the system

### Required hardware
- [AD-96TOF1-EBZ development kit](https://www.analog.com/en/design-center/evaluation-hardware-and-software/evaluation-boards-kits/ad-96tof1-ebz.html)
- [Thor96 Board](https://www.arrow.com/en/products/i.imx8-thor96/arrow-development-tools)
- Thor96 12V power supply (e.g. GST60A12-P1J)
- To run the system in standalone mode, besides the accesories that are provided in the AD-96TOF1-EBZ box you'll need an additional HDMI cable to connect to a monitor and a USB keyboard and mouse

### Power on sequence
- plug the SD card that came in the AD-96TOF1-EBZ box into the Thor96 SD card slot. To benefit from the most recent software updates it is higly recommended to update the SD card with the [latest SD card image](https://github.com/analogdevicesinc/aditof_sdk#supported-embedded-platforms)
- connect the HDMI cable from the monitor to the Thor96 HDMI connector
- connect a USB mouse and keyboard to the Thor96. It's possible to use either a mouse & keyboard combo or a separate mouse and keyboard
- connect the 5V power supply to the camera board and set the camera power switch S2 to on. Once the camera board is powered up the DS1 LED will turn on
- connect the 12V power supply to the Thor96. Once power is connected to the Thor96 the system will boot the Linux OS from the SD card.

### Power off sequence
- remove the 12V supply from the Thor96
- set the camera board power switch to off

### Troubleshooting
- Linux does not boot
  - The SD card is corrupted and this prevents the system from booting. Reflash the SD card with the SD card image.

## Running the evaluation application

Once Linux boots you'll see on the HDMI monitor the Linux desktop and on the top left corner a shortcut to the evaluation application. Double clicking on the icon will start the evaluation application.  A console window will open to show the application's status and, after a few seconds, the evaluation application GUI will be displayed. 

![aditof-demo](https://github.com/analogdevicesinc/aditof_sdk/blob/master/doc/img/aditof_demo.png)

The evaluation application allows to do live streaming of depth and IR data as well as recording the depth and IR data and playing back from a file. The depth data is displayed as a color map ranging from warm to cold colors as the distance from the camera increases. A point in the middle of the depth image shows the distance in mm to the target.

There are 3 operating modes that determine the range of the system:
 - Near - 20cm to 80cm
 - Medium - 80cm to 300cm
 - Far - 300cm to 600cm

When in a certain operating mode the system will measure distances outside of the mode's range but those will not be accurate. 
 
The evaluation application also displays the temperature in deg C of the camera (AFE) and laser boards as read from the temperature sensors installed on each board.

The framerate at which data is acquired from the system is constantly updated on the GUI. The camera board outputs data at 30 frames per second (fps) and the evaluation application processes the frames at same rate.

### Note
 - Use the custom X button which is under the title bar on the top-right side to close the application. Otherwise the application will hang.

### Troubleshooting
- The demo application hangs after closing the main window
  - Due to some limitations the application always hangs if it is closed using the regular X button from the window top bar (title bar). To avoid this unpleasant hang, we've made available a second X button in the top right corner right above the title bar that can be used to safely close the demo application. We hope this to be a temporary workaround.

## Building the SDK

### SDK dependencies
To build the SDK and run the included applications and example code following packages must be present in the system:
 - libopencv-dev
 - cmake
 - glog v0.3.5
 - libwebsockets v3.1
 - protocol buffers v3.5.1

The SD card image already contains all SDK dependencies and there's no need to install them again. To update and build the SDK just follow the steps below.

```console
sh-4.4# cd /home/root/aditof_sdk
sh-4.4# git pull
sh-4.4# rm -rf build
sh-4.4# mkdir build
sh-4.4# cd build
sh-4.4# cmake -DTHOR96=1 -DCMAKE_PREFIX_PATH="/opt/glog;/opt/websockets" ..
sh-4.4# make -j4
``` 

## Linux Kernel
A customized kernel is available for the Thor96 including the V4L2 driver for the ADDI903x. This will be made available on request.
