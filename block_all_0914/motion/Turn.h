#ifndef EV3_MOTION_TURN_H_
#define EV3_MOTION_TURN_H_

#include "Motor.h"
#include "Motion.h"

class Turn : public Motion  {
public:
    Turn(ev3api::Motor& leftWheel,
                    ev3api::Motor& rightWheel,
                    int turn);
    void init() override;
    void run() override;

private:
    ev3api::Motor& mLeftWheel;
    ev3api::Motor& mRightWheel;
    int mTurn;
};

#endif  
