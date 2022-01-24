# Compressor Config with Analog Sensor

## Description

This example shows how to use the REV Analog Pressure Sensor to control the compressor with the PH.

## Usage

Things to check:

* The REV Analog Pressure Sensor is connected to analog channel 0.
* The team number in the project target matches your roboRIO's team number.

Steps:

1. Deploy the code to your roboRIO with the PH connected.
2. Open _Periodic Tasks.vi_, you should see the controls for setting the analog compressor config and indicators for the compressor status.
3. Enable the robot to allow the compressor to run.
4. Use the front panel of Periodic Tasks to set the minimum and maximum pressure values.
5. Click to "Enable Compressor Analog" button to enable compressor control with the analog sensor. The compressor should turn on and run until it reaches the maximum pressure level that you set.
6. Release air from the tank until the pressure is below the minimum pressure level that you set. The compressor should turn on again.
7. Click the "Disable Compressor" button while the compressor is running. This should stop the compressor from running regardless of pressure level.
