// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

package frc.robot;

import edu.wpi.first.wpilibj.PneumaticHub;
import edu.wpi.first.wpilibj.TimedRobot;
import edu.wpi.first.wpilibj.smartdashboard.SmartDashboard;


public class Robot extends TimedRobot {
  private static final int PH_CAN_ID = 1;
  PneumaticHub m_ph = new PneumaticHub(PH_CAN_ID);
  
  @Override
  public void robotInit() {
    // Add buttons to enable/disable the compressor
    SmartDashboard.setDefaultBoolean("Enable Compressor Digital", false);
    SmartDashboard.setDefaultBoolean("Disable Compressor", false);
  }

  @Override
  public void robotPeriodic() {
    /**
     * Get digital pressure switch state and display on Shuffleboard
     */
    SmartDashboard.putBoolean("Digital Pressure Switch",
    m_ph.getPressureSwitch());

    /**
    * Get compressor running status and display on Shuffleboard.
    */
    SmartDashboard.putBoolean("Compressor Running", m_ph.getCompressor());

    // Enable Compressor Digital button
    if (SmartDashboard.getBoolean("Enable Compressor Digital", false)) {
    SmartDashboard.putBoolean("Enable Compressor Digital", false);

    /**
    * Enable the compressor with digital sensor control.
    *
    * This will make the compressor run whenever the pressure switch is closed.
    * If open, (disconnected or reached max pressure), the compressor will shut
    * off.
    */
    m_ph.enableCompressorDigital();
    }

    // Disable Compressor button
    if (SmartDashboard.getBoolean("Disable Compressor", false)) {
    SmartDashboard.putBoolean("Disable Compressor", false);

    /**
    * Disable the compressor.
    */
    m_ph.disableCompressor();
    }
  }

  @Override
  public void autonomousInit() {}

  @Override
  public void autonomousPeriodic() {}

  @Override
  public void teleopInit() {}

  @Override
  public void teleopPeriodic() {}

  @Override
  public void disabledInit() {}

  @Override
  public void disabledPeriodic() {}

  @Override
  public void testInit() {}

  @Override
  public void testPeriodic() {}
}
