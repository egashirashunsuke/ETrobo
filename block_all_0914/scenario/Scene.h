#ifndef EV3_SCENARIO_SCENE_H_
#define EV3_SCENARIO_SCENE_H_

#include "Turn.h"
#include "Angle.h"
#include "Distance.h"
#include "Motor.h"
#include "Motion.h"
#include "Checker.h"
#include "GoStraight.h"
#include "Arm.h"
#include "LineTrace.h"

#include "ArmJudge.h"
#include "ColorJudge.h"
#include "BlockJudge.h"

class Scene {
public:
    Scene(Motion* Motion,
    Checker* mChecker);

    bool run();

private:
    enum State {
        INIT,
        RUN,
    };

    Motion* mMotion;
    Checker* mChecker;
    State mState;

    void execInit();
    bool execRun();
};

#endif  // EV3_APP_SCENE_H_
