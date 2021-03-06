// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

package frc.robot;

import edu.wpi.first.wpilibj.PneumaticHub;
import edu.wpi.first.wpilibj.Solenoid;
import edu.wpi.first.wpilibj.TimedRobot;
import edu.wpi.first.wpilibj.smartdashboard.SmartDashboard;


public class Robot extends TimedRobot {
  private static final int PH_CAN_ID = 1;
  private static final int SOLENOID_CHANNEL = 0;
  PneumaticHub m_pH = new PneumaticHub(PH_CAN_ID);
  Solenoid m_solenoid = m_pH.makeSolenoid(SOLENOID_CHANNEL);

  @Override
  public void robotInit() {
    // Add Set Solenoid button to Shuffleboard
   SmartDashboard.setDefaultBoolean("Set Solenoid", false);
  }

  @Override
  public void robotPeriodic() {
    /**
     * Get the state of the solenoid.
     */
    SmartDashboard.putBoolean("Get Solenoid", m_solenoid.get());
  }

  @Override
  public void autonomousInit() {}

  @Override
  public void autonomousPeriodic() {}

  @Override
  public void teleopInit() {}

  @Override
  public void teleopPeriodic() {
    /**
     * Set the solenoid output.
     */
    m_solenoid.set(SmartDashboard.getBoolean("Set Solenoid", false));
  }

  @Override
  public void disabledInit() {}

  @Override
  public void disabledPeriodic() {}

  @Override
  public void testInit() {}

  @Override
  public void testPeriodic() {}
}
