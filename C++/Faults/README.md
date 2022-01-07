# Faults

### Description
This example shows how to get both normal and sticky faults and how to clear sticky faults on the PH.

### Usage
Things to check:
* `PH_CAN_ID` in _src/include/Robot.h_ should match your device's CAN ID.
* `teamNumber` in _.wpilib/wpilib_preferences.json_ should match your roboRIO's team number.

Steps:
1. Deploy the code to your roboRIO with the PH connected.
2. Open the included _shuffleboard.json_ from this project in Shuffleboard.
3. On Shuffleboard, you should see the faults represented by booleans. `true` (green) denoting there is a fault, and `false` (red) denoting there is no fault.
4. Click the `Clear Sticky Faults` button on Shuffleboard to clear sticky faults on the PH.
