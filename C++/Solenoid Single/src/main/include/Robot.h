// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/PneumaticHub.h>
#include <frc/Solenoid.h>
#include <frc/TimedRobot.h>

#define PH_CAN_ID 1
#define SOLENOID_CHANNEL 0

class Robot : public frc::TimedRobot {
public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;

private:
  frc::PneumaticHub m_PH{PH_CAN_ID};
  frc::Solenoid m_solenoid= m_PH.MakeSolenoid(SOLENOID_CHANNEL);
};
