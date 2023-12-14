#ifndef Arm_H
#define Arm_H

#include <Arduino.h>
#include <Alfredo_NoU2.h>

class Arm
{
    public:
        Arm(NoU_Servo* bottomJoint, NoU_Servo* wrist, NoU_Motor* intakeMotor);
        void begin();

        void set(int fourBarAngle, int secondAngle);
        void set(char position);
        void setIntake(double on);

    private:
        NoU_Servo* _bottomJoint;
        NoU_Servo* _;

        int _angleFourBarStow = 0;
        int _angleSecondStow = 0;

        int _angleFourBarLow = 0;
        int _angleSecondLow = 60;

        int _angleFourBarMid = 30;
        int _angleSecondMid = 85;

        int _angleFourBarHigh = 30;
        int _angleSecondHigh = 75;

        int _angleFourBarDouble = 25;
        int _angleSecondDouble = 80; 

        int _angleFourBarSingle = 0;
        int _angleSecondSingle = 0; 

        int _angleFourBarFloorUpright = 0;     
        int _angleSecondFloorUpright = 93;

        int _angleFourBarFloorFlat = 0;
        int _angleSecondFloorFlat = 0;
};

#endif