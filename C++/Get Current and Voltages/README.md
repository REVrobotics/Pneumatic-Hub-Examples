# Get Current and Voltage

### Description
This example shows how to get the various current and voltage readings from the PH.

### Usage
Things to check:
* `PH_CAN_ID` in _src/include/Robot.h_ should match your device's CAN ID.
* `teamNumber` in _.wpilib/wpilib_preferences.json_ should match your roboRIO's team number.

Steps:
1. Deploy the code to your roboRIO with the PDH connected.
2. Open the included _shuffleboard.json_ from this project in Shuffleboard.
3. Input voltage, solenoid current and voltage, compressor current, analog voltages, and 5V regulated voltage should be displayed on Shuffleboard.