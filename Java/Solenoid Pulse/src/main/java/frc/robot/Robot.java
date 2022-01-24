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
    // Add pulse controls to Shuffleboard
    SmartDashboard.setDefaultBoolean("Start Pulse", false);
    SmartDashboard.setDefaultNumber("Pulse Duration (ms)", 500);
  }

  @Override
  public void robotPeriodic() {
    /**
     * Get the state of the solenoid.
     */
    SmartDashboard.putBoolean("Get Solenoid", m_solenoid.get());

    /**
     * Update the pulse duration.
     *
     * This will be how long the solenoid will be on.
     */
    double pulseDuration =
        SmartDashboard.getNumber("Pulse Duration (ms)", 0) /1000;
    m_solenoid.setPulseDuration(pulseDuration);
  }

  @Override
  public void autonomousInit() {}

  @Override
  public void autonomousPeriodic() {}

  @Override
  public void teleopInit() {}

  @Override
  public void teleopPeriodic() {
    // Start Pulse button
    if (SmartDashboard.getBoolean("Start Pulse", false)) {
      SmartDashboard.putBoolean("Start Pulse", false);

      /**
       * Start the pulse of the solenoid.
       *
       * The solenoid will be on for however long you specified.
       */
      m_solenoid.startPulse();
    }
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
