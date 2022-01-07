// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

package frc.robot;

import edu.wpi.first.wpilibj.DoubleSolenoid;
import edu.wpi.first.wpilibj.PneumaticsModuleType;
import edu.wpi.first.wpilibj.TimedRobot;
import edu.wpi.first.wpilibj.smartdashboard.SmartDashboard;

public class Robot extends TimedRobot {
  
  private static int forwardChannel =0;
  private static int reverseChannel =1;
  DoubleSolenoid m_doubleSolenoid = new DoubleSolenoid(PneumaticsModuleType.REVPH,forwardChannel,reverseChannel );

  @Override
  public void robotInit() {
    // Add buttons to set the double
    SmartDashboard.setDefaultBoolean("Set Off", false);
    SmartDashboard.setDefaultBoolean("Set Forward", false);
    SmartDashboard.setDefaultBoolean("Set Reverse", false);
  }

  @Override
  public void robotPeriodic() {
    /**
     * Get the state of the solenoid.
     *
     * This is just a switch case to better display it on Shuffleboard.
     */
    switch (m_doubleSolenoid.get()) {
      case kOff:
        SmartDashboard.putString("Get Solenoid", "kOff");
        break;
      case kForward:
        SmartDashboard.putString("Get Solenoid", "kForward");
        break;
      case kReverse:
        SmartDashboard.putString("Get Solenoid", "kReverse");
        break;
      default:
        SmartDashboard.putString("Get Solenoid", "N/A");
        break;
    }
  }

  @Override
  public void autonomousInit() {}

  @Override
  public void autonomousPeriodic() {}

  @Override
  public void teleopInit() {}

  @Override
  public void teleopPeriodic() {
    // Set Off Button
    if (SmartDashboard.getBoolean("Set Off", false)) {
      SmartDashboard.putBoolean("Set Off", false);

      /**
       * Set the double solenoid to OFF.
       *
       * This will set both the forward and reverse solenoid channels to false.
       */
      m_doubleSolenoid.set(DoubleSolenoid.Value.kOff);
    }

    // Set Forward button
    if (SmartDashboard.getBoolean("Set Forward", false)) {
      SmartDashboard.putBoolean("Set Forward", false);

      /**
       * Set the double solenoid direction to FORWARD.
       *
       * This will set the forward solenoid channel to true and the reverse
       * solenoid channel to false.
       */
      m_doubleSolenoid.set(DoubleSolenoid.Value.kForward);
    }

    // Set Reverse button
    if (SmartDashboard.getBoolean("Set Reverse", false)) {
      SmartDashboard.putBoolean("Set Reverse", false);

      /**
       * Set the double solenoid direction to REVERSE.
       *
       * This will set the forward solenoid channel to false and the reverse
       * solenoid channel to true.
       */
      m_doubleSolenoid.set(DoubleSolenoid.Value.kReverse);
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
