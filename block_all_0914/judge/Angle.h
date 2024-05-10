#ifndef EV3_JUDGE_ANGLE_H_
#define EV3_JUDGE_ANGLE_H_
#include "Motor.h"
#include "Checker.h"

class Angle : public Checker {
public:

    Angle(ev3api::Motor& leftWheel,
                    ev3api::Motor& rightWheel,
                    int targetangle,
                    int turn);

    void init() override;
    bool judge() override;

private:
    ev3api::Motor& mLeftWheel;
    ev3api::Motor& mRightWheel;
    int angle;
    int mTargetAngle;
    int mTurn;
};

#endif  