// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "PivotAttackPositionCommand.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

PivotAttackPositionCommand::PivotAttackPositionCommand(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::ballManipulation.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES

	this->isAtBottom = false;
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void PivotAttackPositionCommand::Initialize() {
	this->isAtBottom = false;
}

// Called repeatedly when this Command is scheduled to run
void PivotAttackPositionCommand::Execute() {
	if (Robot::ballManipulation->getBottomSwitchLimit() == false) {
		this->isAtBottom = true;
	}

	if (this->isAtBottom != true) {
		Robot::ballManipulation->driveBallPivotDown();
	} else {
		Robot::ballManipulation->driveBallPivotUp();
	}

}

// Make this return true when this Command no longer needs to run execute()
bool PivotAttackPositionCommand::IsFinished() {
	return Robot::ballManipulation->getPivotEncoder() >= TARGET_PIVOT_REVOLUTION;
}

// Called once after isFinished returns true
void PivotAttackPositionCommand::End() {
	Robot::ballManipulation->stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PivotAttackPositionCommand::Interrupted() {
	this->End();
}
