// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

package frc.robot;

import edu.wpi.first.math.util.Units;
import edu.wpi.first.wpilibj.PneumaticHub;
import edu.wpi.first.wpilibj.TimedRobot;
import edu.wpi.first.wpilibj.smartdashboard.SmartDashboard;


public class Robot extends TimedRobot {
  private static final int PH_CAN_ID = 1;
  PneumaticHub m_ph = new PneumaticHub(PH_CAN_ID);
  @Override
  public void robotInit() {
    SmartDashboard.setDefaultBoolean("Enable Compressor Analog", false);
    SmartDashboard.setDefaultBoolean("Disable Compressor", false);
  
    // Add number inputs for minimum and maximum pressure
    SmartDashboard.setDefaultNumber("Minimum Pressure (PSI)", 100.0);
    SmartDashboard.setDefaultNumber("Maximum Pressure (PSI)", 120.0);
  }

  @Override
  public void robotPeriodic() {
    /**
     * Get pressure from analog channel 0 and display on Shuffleboard.
     */
    SmartDashboard.putNumber("Pressure", m_ph.getPressure(0));

    /**
     * Get compressor running status and display on Shuffleboard.
     */
    SmartDashboard.putBoolean("Compressor Running", m_ph.getCompressor());

    // Enable Compressor Analog button
    if (SmartDashboard.getBoolean("Enable Compressor Analog", false)) {
      SmartDashboard.putBoolean("Enable Compressor Analog", false);

      // Get values from Shuffleboard
      double minPressure =
          SmartDashboard.getNumber("Minimum Pressure (PSI)", 0.0);
      double maxPressure =
          SmartDashboard.getNumber("Maximum Pressure (PSI)", 0.0);

      /**
       * Enable the compressor with analog pressure sensor control.
       *
       * This uses hysteresis between a minimum and maximum pressure value,
       * the compressor will run when the sensor reads below the minimum pressure
       * value, and the compressor will shut off once it reaches the maximum.
       *
       *
       */
      m_ph.enableCompressorAnalog(minPressure,maxPressure);
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
