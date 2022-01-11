# Compressor Config with Hybrid Control

## Description

This example shows how to use both a digital pressure switch and the REV Analog Pressure Sensor to control the compressor with the PH.

## Usage

Things to check:

* The REV Analog Pressure Sensor is connected to analog channel 0.
* The digital pressure switch is connected to the digital channel on the PH.
* The team number in the project target matches your roboRIO's team number.

Steps:

1. Deploy the code to your roboRIO with the PH connected.
2. Open _Periodic Tasks.vi_, you should see the controls for setting the analog compressor config and indicators for the compressor status.
3. Enable the robot to allow the compressor to run.
4. Use the front panel of Period Tasks to set the minimum and maximum pressure values.
5. Click to "Enable Compressor Hybrid" button to enable compressor control with both the digital and analog sensor. The compressor should turn on when below the minimum pressure sensor that you set, and it should shut off when the maximum pressure that you set is reached OR if the digital pressure switch is open.
6. Click the "Disable Compressor" button while the compressor is running. This should stop the compressor from running regardless of pressure level or digital pressure switch state.
