# Installing the software

## Context

These instructions assume that you are using a recent Linux Ubuntu or Mint installation.
 
You'll find details for Windows or OSX online but I have not tested them.

You will only need to install FORTH once. The process (described below) is very simple and should only take a
couple of minutes.


## Prerequisites


Once you have wired up your breadboard or soldered your perma-proto board,
make sure you have a (temporary) resistor connecting IC pin 24 and ground.

This is needed *only* for image installation

1. install `lpc21isp`.


    sudo apt-get install lpc21isp
    
    

2. Next, download the [mecrisp-stellaris archive]().

Extract it to a directory of your choice and change to that directory.

    cd ~/<mecrisp-stellaris direectory>
    
3. Connect your USB-to-serial cable or cp2102 and plug it into the LPC1114 board.

![Board with CP2103 inserted](images/v2.0-cropped.jpg)

4. Now press the reset button on the breadboard/perma-proto board and
run the following command:

    lpc21isp -bin mecrisp-stellaris-lpc1114fn28.bin /dev/ttyUSB0 115200 48000
    
You should see a screen like this:




