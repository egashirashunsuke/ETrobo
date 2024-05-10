#ifndef EV3_MOTION_LINETRACE_H_
#define EV3_MOTION_LINETRACE_H_

#include "Motion.h"

#include "LineMonitor.h"
#include "Walker.h"

class LineTrace : public Motion {
public:
static const float TARGET_VAL;
    LineTrace(const LineMonitor* lineMonitor,
               Walker* walker);

    void init() override;
    void run() override;
    float pid(float sensor_val,float target_val);

private:
    const LineMonitor* mLineMonitor;
    Walker* mWalker;

    int calcDirection(float isOnLine);
};

#endif  // EV3_UNIT_LINETRACE_H
