# Single Solenoids

### Description
This example shows how to use a single acting solenoid with the PH.

### Usage
Things to check:
* `PH_CAN_ID` in _src/include/Robot.h_ should match your device's CAN ID.
* `teamNumber` in _.wpilib/wpilib_preferences.json_ should match your roboRIO's team number.

Steps:
1. Deploy the code to your roboRIO with the PH connected.
2. Open the included _shuffleboard.json_ from this project in Shuffleboard.
3. Enable the robot to allow the solenoid actuation.
4. Click the `Set Solenoid` button to toggle the solenoid channel (0).
5. The `Get Solenoid` boolean will show you the state of the solenoid channel (0).