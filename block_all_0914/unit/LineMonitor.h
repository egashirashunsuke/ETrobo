#ifndef EV3_UNIT_LINEMONITOR_H_
#define EV3_UNIT_LINEMONITOR_H_

#include "ColorSensor.h"
#include "SonarSensor.h"

// 定義
class LineMonitor {
public:
    explicit LineMonitor(const ev3api::ColorSensor& colorSensor);
    float isOnLine_gray() const; 
    int getRgbColor() const; 

private:
    const ev3api::ColorSensor& mColorSensor;
};

#endif  // EV3_UNIT_LINEMONITOR_H_
