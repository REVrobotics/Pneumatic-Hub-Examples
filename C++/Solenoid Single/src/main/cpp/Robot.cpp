// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
  // Add Set Solenoid button to Shuffleboard
  frc::SmartDashboard::SetDefaultBoolean("Set Solenoid", false);
}

void Robot::RobotPeriodic() {
  /**
   * Get the state of the solenoid.
   */
  frc::SmartDashboard::PutBoolean("Get Solenoid", m_solenoid.Get());
}

void Robot::AutonomousInit() {}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {
  /**
   * Set the solenoid output.
   */
  m_solenoid.Set(frc::SmartDashboard::GetBoolean("Set Solenoid", false));
}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
