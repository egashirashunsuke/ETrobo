#ifndef EV3_STCTRL_H_
#define EV3_STCTRL_H_

#include "Motor.h"

class StraightCtrl {
public:
    StraightCtrl(ev3api::Motor& leftWheel,
                    ev3api::Motor& rightWheel,
                    int direction);

    void init() ;
    int judge() ;

private:
    ev3api::Motor& mLeftWheel;
    ev3api::Motor& mRightWheel;
    int32_t angle;
    int mDireciton;
};

#endif  // EV3_UNIT_STCTRL_H
