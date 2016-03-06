// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#ifndef BALLMANIPULATION_H
#define BALLMANIPULATION_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class BallManipulation: public Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	std::shared_ptr<DigitalInput> bottomLimitSwitch;
	std::shared_ptr<CANTalon> pivotMotor;
	std::shared_ptr<CANTalon> fetchMotor;
	std::shared_ptr<RobotDrive> ballMotor21;
	std::shared_ptr<DigitalInput> topLimitSwitch;
	std::shared_ptr<Encoder> pivotEncoder;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
public:
	BallManipulation();
	void InitDefaultCommand();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
	void driveBallRelease();
	void driveBallHold();
	void driveBallPivotUp();
	void driveBallPivotDown();
	void stop();

	bool getBottomSwitchLimit();
	bool getTopSwitchLimit();
	int getPivotEncoder();
};

#endif
