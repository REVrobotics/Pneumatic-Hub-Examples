# Single Solenoids

## Description

This example shows how to use a single acting solenoid with the PH.

## Usage

Things to check:

* The team number in the project target matches your roboRIO's team number.

Steps:

1. Deploy the code to your roboRIO with the PH connected.
2. Open _Teleop.vi_, you should see controls and indicators on the front panel.
3. Enable the robot to allow the solenoid actuation.
4. Click the `Set Solenoid` button to toggle the solenoid channel (0).
5. The `Get Solenoid` boolean will show you the state of the solenoid channel (0).