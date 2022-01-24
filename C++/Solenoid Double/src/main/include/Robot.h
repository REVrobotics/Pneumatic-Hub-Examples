// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/PneumaticHub.h>
#include <frc/DoubleSolenoid.h>
#include <frc/TimedRobot.h>

#define PH_CAN_ID 1
#define SOLENOID_FORWARD_CHANNEL 0
#define SOLENOID_REVERSE_CHANNEL 1

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
  frc::DoubleSolenoid m_doubleSolenoid= m_PH.MakeDoubleSolenoid(SOLENOID_FORWARD_CHANNEL,SOLENOID_REVERSE_CHANNEL);
};
