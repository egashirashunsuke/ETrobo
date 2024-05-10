#ifndef EV3_JUDGE_BLOCKJUDGE_H
#define EV3_JUDGE_BLOCKJUDGE_H_
#include "Motor.h"
#include "ColorSensor.h"
#include "Checker.h"

class BlockJudge : public Checker {
public:
    BlockJudge(const ev3api::ColorSensor& colorSensor,
                        float blockDist);

    void init() override;
    bool judge() override;

private:
    rgb_raw_t rgb_raw;
    const ev3api::ColorSensor& color;
    float blockDist;
};

#endif  