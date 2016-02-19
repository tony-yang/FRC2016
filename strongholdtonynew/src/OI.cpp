// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/BallPivotCommand.h"
#include "Commands/BallReleaseCommand.h"
#include "Commands/DriveWithJoysticks.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
    // Process operator interface input here.
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    driverJoystick.reset(new Joystick(1));
    
    ballReleaseControl.reset(new JoystickButton(driverJoystick.get(), 4));
    ballReleaseControl->WhenPressed(new BallReleaseCommand(false));
    ballPivotControl.reset(new JoystickButton(driverJoystick.get(), 3));
    ballPivotControl->WhenPressed(new BallPivotCommand());

    // SmartDashboard Buttons
    SmartDashboard::PutData("BallReleaseCommand: HOLD", new BallReleaseCommand(false));
    SmartDashboard::PutData("BallReleaseCommand: RELEASE", new BallReleaseCommand(true));
    SmartDashboard::PutData("BallPivotCommand", new BallPivotCommand());
    SmartDashboard::PutData("Drive With Joysticks: STOP", new DriveWithJoysticks(0, 0, 0));
    SmartDashboard::PutData("Autonomous Command: FORWARD", new AutonomousCommand(0, 0));

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<Joystick> OI::getDriverJoystick() {
   return driverJoystick;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
