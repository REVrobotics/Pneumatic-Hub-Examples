# Compressor Config with Digital Pressure Switch

### Description
This example shows how to use a digital pressure switch to control the compressor with the PH.

### Usage
Things to check:
* The digital pressure switch is connected to the digital channel on the PH.
* `PH_CAN_ID` in _src/include/Robot.h_ should match your device's CAN ID.
* `teamNumber` in _.wpilib/wpilib_preferences.json_ should match your roboRIO's team number.

Steps:
1. Deploy the code to your roboRIO with the PH connected.
2. Open the included _shuffleboard.json_ from this project in Shuffleboard.
3. Enable the robot to allow the compressor to run.
4. Click to "Enable Compressor Digital" button to enable compressor control with the digital pressure switch. The compressor should turn on when the digital pressure switch is closed, and it should shut off when it is open.
5. Click the "Disable Compressor" button while the compressor is running. This should stop the compressor from running regardless of digital pressure switch state.