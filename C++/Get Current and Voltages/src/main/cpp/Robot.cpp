// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {}

void Robot::RobotPeriodic() {
  /**
   * PH input voltage.
   */
  frc::SmartDashboard::PutNumber("Input Voltage",
                                 m_ph.GetInputVoltage().value());

  /**
   * Solenoids total current and voltage.
   */
  frc::SmartDashboard::PutNumber("Total Solenoid Current",
                                 m_ph.GetSolenoidsTotalCurrent().value());
  frc::SmartDashboard::PutNumber("Solenoid Voltage",
                                 m_ph.GetSolenoidsVoltage().value());

  /**
   * Compressor current.
   */
  frc::SmartDashboard::PutNumber("Compressor Current",
                                 m_ph.GetCompressorCurrent().value());

  /**
   * Analog sensor voltages.
   */
  frc::SmartDashboard::PutNumber("Analog Voltage 0",
                                 m_ph.GetAnalogVoltage(0).value());
  frc::SmartDashboard::PutNumber("Analog Voltage 1",
                                 m_ph.GetAnalogVoltage(1).value());

  /**
   * 5V Regulated Voltage.
   *
   * This is used for analog pressure sensor calculations.
   */
  frc::SmartDashboard::PutNumber("5V Voltage",
                                 m_ph.Get5VRegulatedVoltage().value());
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
