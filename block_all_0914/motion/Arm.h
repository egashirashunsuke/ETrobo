#ifndef EV3_MOTION_ARM_H_
#define EV3_MOTION_ARM_H_

#include "Motor.h"
#include "Motion.h"


class Arm : public Motion {
public:
    Arm(ev3api::Motor& Arm,int turn);

    void init() override;
    void run() override;

private:
    ev3api::Motor& mArm;
    int mTurn;
};

#endif  // EV3_UNIT_GOSTRAIGHT_H
