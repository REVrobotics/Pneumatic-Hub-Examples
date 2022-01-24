# Compressor Config with Digital Sensor

## Description

This example shows how to use digital pressure sensor to control the compressor with the PH.

## Usage

Things to check:

* The digital pressure switch is connected to the digital channel.
* The team number in the project target matches your roboRIO's team number.

Steps:

1. Deploy the code to your roboRIO with the PH connected.
2. Open _Periodic Tasks.vi_, you should see the controls for setting enabling and disabling the compressor and indicators for the compressor status.
3. Enable the robot to allow the compressor to run.
4. Click to "Enable Compressor Digital" button to enable compressor control with the digital pressure switch. The compressor should turn on when the digital pressure switch is closed, and it should shut off when it is open.
5. Click the "Disable Compressor" button while the compressor is running. This should stop the compressor from running regardless of digital pressure switch state.
