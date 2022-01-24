# Double Solenoids

## Description

This example shows how to use a double acting solenoid with the PH.

## Usage

Things to check:

* The team number in the project target matches your roboRIO's team number.

Steps:

1. Deploy the code to your roboRIO with the PH connected.
2. Open _Teleop.vi_, you should see controls and indicators on the front panel.
3. Enable the robot to allow the solenoid actuation.
4. Click the `Set Off` button to turn off both the forward and reverse channels of the double solenoid.
5. Click the `Set Forward` to set the direction of the double solenoid to forward i.e. forward channel is on and reverse channel is off.
6. Click the `Set Reverse` to set the direction of the double solenoid to reverse i.e. forward channel is off and reverse channel is on.
7. The `Get Solenoid` indicator will display the double solenoid's current state.
