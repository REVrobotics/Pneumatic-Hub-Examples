// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
  // Add buttons to enable/disable the compressor
  frc::SmartDashboard::SetDefaultBoolean("Enable Compressor Digital", false);
  frc::SmartDashboard::SetDefaultBoolean("Disable Compressor", false);
}

void Robot::RobotPeriodic() {
  /**
   * Get digital pressure switch state and display on Shuffleboard
   */
  frc::SmartDashboard::PutBoolean("Digital Pressure Switch",
                                  m_ph.GetPressureSwitch());

  /**
   * Get compressor running status and display on Shuffleboard.
   */
  frc::SmartDashboard::PutBoolean("Compressor Running", m_ph.GetCompressor());

  // Enable Compressor Digital button
  if (frc::SmartDashboard::GetBoolean("Enable Compressor Digital", false)) {
    frc::SmartDashboard::PutBoolean("Enable Compressor Digital", false);

    /**
     * Enable the compressor with digital sensor control.
     *
     * This will make the compressor run whenever the pressure switch is closed.
     * If open, (disconnected or reached max pressure), the compressor will shut
     * off.
     */
    m_ph.EnableCompressorDigital();
  }

  // Disable Compressor button
  if (frc::SmartDashboard::GetBoolean("Disable Compressor", false)) {
    frc::SmartDashboard::PutBoolean("Disable Compressor", false);

    /**
     * Disable the compressor.
     */
    m_ph.DisableCompressor();
  }
}

void Robot::AutonomousInit() {}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
