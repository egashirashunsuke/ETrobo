#ifndef EV3_JUDGE_DISTANCE_H_
#define EV3_JUDGE_DISTANCE_H_
#include "Motor.h"
#include "Checker.h"

class Distance : public Checker {
public:
    Distance(ev3api::Motor& leftWheel,
                    ev3api::Motor& rightWheel,
                    int32_t targetangle,
                    int direction);

    void init() override;
    bool judge() override;

private:
    ev3api::Motor& mLeftWheel;
    ev3api::Motor& mRightWheel;
    int32_t angle;
    int32_t mTargetAngle;
    int mDireciton;
};

#endif  