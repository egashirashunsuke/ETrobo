#ifndef EV3_JUDGE_COLORJUDGE_H
#define EV3_JUDGE_COLORJUDGE_H_
#include "Motor.h"
#include "ColorSensor.h"
#include "Checker.h"

class ColorJudge : public Checker {
public:
    ColorJudge(const ev3api::ColorSensor& colorSensor,
                        colorid_t targetColor);

    void init() override;
    bool judge() override;

private:
    rgb_raw_t rgb_raw;
    const ev3api::ColorSensor& color;
    colorid_t targetColor;
};

#endif  