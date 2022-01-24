# Solenoid Pulse

### Description
This example shows how to pulse a solenoid with the REV PH.

### Usage
Things to check:
* `PH_CAN_ID` in _src/main/java/frc/robot/Robot.java_  should match your device's CAN ID.
* `teamNumber` in _.wpilib/wpilib_preferences.json_ should match your roboRIO's team number.

Steps:
1. Deploy the code to your roboRIO with the PH connected.
2. Open the included _shuffleboard.json_ from this project in Shuffleboard.
3. Enable the robot to allow the solenoid actuation.
4. The `Pulse Duration (ms)` field will control how long the solenoid channel will be on.
5. Click the `Start Pulse` button to start the pulse of the solenoid channel. The solenoid channel will be on for however long you set it.
5. The `Get Solenoid` boolean will show you the state of the solenoid channel.