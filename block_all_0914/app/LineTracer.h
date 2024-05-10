#ifndef EV3_APP_LINETRACER_H_
#define EV3_APP_LINETRACER_H_

#include "LineMonitor.h"
#include "Walker.h"
#include "Checker.h"

class LineTracer {
public:
    static const float TARGET_VAL;
    LineTracer(const LineMonitor* lineMonitor,
               Walker* walker,
               Checker* colorRed);
    bool run();
    float pid(float KP, float KI, float KD, float sensor_val,float target_val);

private:
    const LineMonitor* mLineMonitor;
    Walker* mWalker;
    Checker* mColorJudgeRed;

    int calcDirectionL(float isOnLine);
    int calcDirectionR(float isOnLine);
};

#endif  // EV3_APP_LINETRACER_H_
