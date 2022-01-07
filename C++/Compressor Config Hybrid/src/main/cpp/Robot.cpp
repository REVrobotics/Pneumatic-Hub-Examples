// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
  // Add buttons to enable/disable the compressor
  frc::SmartDashboard::SetDefaultBoolean("Enable Compressor Hybrid", false);
  frc::SmartDashboard::SetDefaultBoolean("Disable Compressor", false);

  // Add number inputs for minimum and maximum pressure
  frc::SmartDashboard::SetDefaultNumber("Minimum Pressure (PSI)", 100.0);
  frc::SmartDashboard::SetDefaultNumber("Maximum Pressure (PSI)", 120.0);
}

void Robot::RobotPeriodic() {
  /**
   * Get digital pressure switch state and display on Shuffleboard.
   */
  frc::SmartDashboard::PutBoolean("Digital Pressure Switch",
                                  m_ph.GetPressureSwitch());

  /**
   * Get pressure from analog channel 0 and display on Shuffleboard.
   */
  frc::SmartDashboard::PutNumber("Pressure", m_ph.GetPressure(0).value());

  /**
   * Get compressor running status and display on Shuffleboard.
   */
  frc::SmartDashboard::PutBoolean("Compressor Running", m_ph.GetCompressor());

  // Enable Compressor Hybrid button
  if (frc::SmartDashboard::GetBoolean("Enable Compressor Hybrid", false)) {
    frc::SmartDashboard::PutBoolean("Enable Compressor Hybrid", false);

    // Get values from Shuffleboard
    double minPressure =
        frc::SmartDashboard::GetNumber("Minimum Pressure (PSI)", 0.0);
    double maxPressure =
        frc::SmartDashboard::GetNumber("Maximum Pressure (PSI)", 0.0);

    /**
     * Enable the compressor with hybrid sensor control, meaning it uses both
     * the analog and digital pressure sensors.
     *
     * This uses hysteresis between a minimum and maximum pressure value,
     * the compressor will run when the sensor reads below the minimum pressure
     * value, and the compressor will shut off once it reaches the maximum.
     *
     * If at any point the digital pressure switch is open, the compressor will
     * shut off.
     */
    m_ph.EnableCompressorHybrid(units::pounds_per_square_inch_t{minPressure},
                                units::pounds_per_square_inch_t{maxPressure});
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
