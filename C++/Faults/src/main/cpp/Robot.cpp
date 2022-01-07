// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>

/**
 * Helper function to display PH normal faults on Shuffleboard.
 */
void printFaults(frc::PneumaticHub::Faults faults) {
  frc::SmartDashboard::PutBoolean("Channel 0", faults.Channel0Fault);
  frc::SmartDashboard::PutBoolean("Channel 1", faults.Channel1Fault);
  frc::SmartDashboard::PutBoolean("Channel 2", faults.Channel2Fault);
  frc::SmartDashboard::PutBoolean("Channel 3", faults.Channel3Fault);
  frc::SmartDashboard::PutBoolean("Channel 4", faults.Channel4Fault);
  frc::SmartDashboard::PutBoolean("Channel 5", faults.Channel5Fault);
  frc::SmartDashboard::PutBoolean("Channel 6", faults.Channel6Fault);
  frc::SmartDashboard::PutBoolean("Channel 7", faults.Channel7Fault);
  frc::SmartDashboard::PutBoolean("Channel 8", faults.Channel8Fault);
  frc::SmartDashboard::PutBoolean("Channel 9", faults.Channel9Fault);
  frc::SmartDashboard::PutBoolean("Channel 10", faults.Channel10Fault);
  frc::SmartDashboard::PutBoolean("Channel 11", faults.Channel11Fault);
  frc::SmartDashboard::PutBoolean("Channel 12", faults.Channel12Fault);
  frc::SmartDashboard::PutBoolean("Channel 13", faults.Channel13Fault);
  frc::SmartDashboard::PutBoolean("Channel 14", faults.Channel14Fault);
  frc::SmartDashboard::PutBoolean("Channel 15", faults.Channel15Fault);
  frc::SmartDashboard::PutBoolean("Solenoid OC", faults.SolenoidOverCurrent);
  frc::SmartDashboard::PutBoolean("Compressor Open", faults.CompressorOpen);
  frc::SmartDashboard::PutBoolean("Compressor OC",
                                  faults.CompressorOverCurrent);
  frc::SmartDashboard::PutBoolean("Brownout", faults.Brownout);
  frc::SmartDashboard::PutBoolean("CAN Warning", faults.CanWarning);
  frc::SmartDashboard::PutBoolean("Hardware", faults.HardwareFault);
}

/**
 * Helper function to display PH sticky faults on Shuffleboard.
 */
void printStickyFaults(frc::PneumaticHub::StickyFaults stickyFaults) {
  frc::SmartDashboard::PutBoolean("Sticky Solenoid OC",
                                  stickyFaults.SolenoidOverCurrent);
  frc::SmartDashboard::PutBoolean("Sticky Compressor Open",
                                  stickyFaults.CompressorOpen);
  frc::SmartDashboard::PutBoolean("Sticky Compressor OC",
                                  stickyFaults.CompressorOverCurrent);
  frc::SmartDashboard::PutBoolean("Sticky Brownout", stickyFaults.Brownout);
  frc::SmartDashboard::PutBoolean("Sticky CAN Bus Off", stickyFaults.CanBusOff);
  frc::SmartDashboard::PutBoolean("Sticky CAN Warning",
                                  stickyFaults.CanWarning);
  frc::SmartDashboard::PutBoolean("Sticky Has Reset", stickyFaults.HasReset);
}

void Robot::RobotInit() {
  // Add button to Shuffleboard to clear sticky faults
  frc::SmartDashboard::SetDefaultBoolean("Clear Sticky Faults", false);
}

void Robot::RobotPeriodic() {
  /**
   * Get faults from the PH and display them onto Shuffleboard.
   */
  frc::PneumaticHub::Faults faults = m_ph.GetFaults();
  printFaults(faults);

  /**
   * Get sticky faults from the PH and display them on Shuffleboard.
   *
   * Sticky faults are different from normal faults because they "stick", even
   * after the normal fault is cleared. The sticky version of the fault is
   * always set when the normal version is set. To clear sticky faults, see
   * below.
   */
  frc::PneumaticHub::StickyFaults stickyFaults = m_ph.GetStickyFaults();
  printStickyFaults(stickyFaults);

  // Check Clear Sticky Faults button status
  if (frc::SmartDashboard::GetBoolean("Clear Sticky Faults", false)) {
    frc::SmartDashboard::PutBoolean("Clear Sticky Faults", false);

    /**
     * Clear sticky faults on the PH.
     *
     * This clears sticky faults if their corresponding normal fault is also
     * clear. If the normal fault is still set, the sticky fault will remain
     * set.
     */
    m_ph.ClearStickyFaults();
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
