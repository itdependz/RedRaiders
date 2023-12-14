#include <Arm.h>

Arm::Arm(NoU_Servo* bottomJoint, NoU_Servo* wrist, NoU_Motor* intakeMotor)
                                    : _bottomJoint(fourbarJoint), _wrist(wrist), _intakeMotor(intakeMotor)
{ }

void Arm::begin(){
    set('s');
  _intakeMotor->set(0);
}

void Arm::set(int fourBarAngle, int secondAngle) {
    _fourBarJoint->write(180 - fourBarAngle);
    _secondJoint->write(180 - secondAngle);
}

void Arm::set(char position) {
    if (position == 's') {
        set(_angleFourBarStow, _angleSecondStow);
    }
    else if (position == 'l') {
        set(_angleFourBarLow, _angleSecondLow);
    }
    else if (position == 'm') {
        set(_angleFourBarMid, _angleSecondMid);
    }
    else if (position == 'h') {
        set(_angleFourBarHigh, _angleSecondHigh);
    }
    else if (position == 'd') {
        set(_angleFourBarDouble, _angleSecondDouble);
    }
    else if (position == 'f') {
        set(_angleFourBarFloorUpright, _angleSecondFloorUpright);
    }
    else if (position == 'F') {
        set(_angleFourBarFloorFlat, _angleSecondFloorFlat);
    }
    else if (position == 'i') {
        setIntake(1);
    }
    else if (position == 'o') {
        setIntake(-1);
    }
    else if (position == 'x') {
        setIntake(0);
    }
    else if (position == 't') {
        set(_angleFourBarSingle, _angleSecondSingle);
    }
    else {
        set(_angleFourBarStow, _angleSecondStow);
    }
}

void Arm::setIntake(double on) {
    _intakeMotor->set(on);
}