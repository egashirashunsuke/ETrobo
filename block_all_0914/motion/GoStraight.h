#ifndef EV3_MOTION_GOSTRAIGHT_H_
#define EV3_MOTION_GOSTRAIGHT_H_

#include "Motor.h"
#include "Motion.h"
#include "StraightCtrl.h"


class GoStraight : public Motion {
public:
    GoStraight(ev3api::Motor& leftWheel,
                    ev3api::Motor& rightWheel,
                    int pwm);

    void init() override;
    void run() override;

private:
    ev3api::Motor& mLeftWheel;
    ev3api::Motor& mRightWheel;
    int mPwm;
    StraightCtrl mStraightCtrl;
};

#endif  // EV3_UNIT_GOSTRAIGHT_H
