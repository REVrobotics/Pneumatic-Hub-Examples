// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
  // Add buttons to set the double
  frc::SmartDashboard::SetDefaultBoolean("Set Off", false);
  frc::SmartDashboard::SetDefaultBoolean("Set Forward", false);
  frc::SmartDashboard::SetDefaultBoolean("Set Reverse", false);
}

void Robot::RobotPeriodic() {
  /**
   * Get the state of the solenoid.
   *
   * This is just a switch case to better display it on Shuffleboard.
   */
  switch (m_doubleSolenoid.Get()) {
  case frc::DoubleSolenoid::kOff:
    frc::SmartDashboard::PutString("Get Solenoid", "kOff");
    break;
  case frc::DoubleSolenoid::kForward:
    frc::SmartDashboard::PutString("Get Solenoid", "kForward");
    break;
  case frc::DoubleSolenoid::kReverse:
    frc::SmartDashboard::PutString("Get Solenoid", "kReverse");
    break;
  default:
    frc::SmartDashboard::PutString("Get Solenoid", "N/A");
    break;
  }
}

void Robot::AutonomousInit() {}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {
  // Set Off Button
  if (frc::SmartDashboard::GetBoolean("Set Off", false)) {
    frc::SmartDashboard::PutBoolean("Set Off", false);

    /**
     * Set the double solenoid to OFF.
     *
     * This will set both the forward and reverse solenoid channels to false.
     */
    m_doubleSolenoid.Set(frc::DoubleSolenoid::kOff);
  }

  // Set Forward button
  if (frc::SmartDashboard::GetBoolean("Set Forward", false)) {
    frc::SmartDashboard::PutBoolean("Set Forward", false);

    /**
     * Set the double solenoid direction to FORWARD.
     *
     * This will set the forward solenoid channel to true and the reverse
     * solenoid channel to false.
     */
    m_doubleSolenoid.Set(frc::DoubleSolenoid::kForward);
  }

  // Set Reverse button
  if (frc::SmartDashboard::GetBoolean("Set Reverse", false)) {
    frc::SmartDashboard::PutBoolean("Set Reverse", false);

    /**
     * Set the double solenoid direction to REVERSE.
     *
     * This will set the forward solenoid channel to false and the reverse
     * solenoid channel to true.
     */
    m_doubleSolenoid.Set(frc::DoubleSolenoid::kReverse);
  }
}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
