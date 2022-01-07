// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
  // Add pulse controls to Shuffleboard
  frc::SmartDashboard::SetDefaultBoolean("Start Pulse", false);
  frc::SmartDashboard::SetDefaultNumber("Pulse Duration (ms)", 500);
}

void Robot::RobotPeriodic() {
  /**
   * Get the state of the solenoid.
   */
  frc::SmartDashboard::PutBoolean("Get Solenoid", m_solenoid.Get());

  /**
   * Update the pulse duration.
   *
   * This will be how long the solenoid will be on.
   *
   * TODO: Fix units once fixed in wpilib. They are seconds right now but are
   * actually being treated as milliseconds.
   */
  double pulseDuration =
      frc::SmartDashboard::GetNumber("Pulse Duration (ms)", false);
  m_solenoid.SetPulseDuration(units::second_t{pulseDuration});
}

void Robot::AutonomousInit() {}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {
  // Start Pulse button
  if (frc::SmartDashboard::GetBoolean("Start Pulse", false)) {
    frc::SmartDashboard::PutBoolean("Start Pulse", false);

    /**
     * Start the pulse of the solenoid.
     *
     * The solenoid will be on for however long you specified.
     */
    m_solenoid.StartPulse();
  }
}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
