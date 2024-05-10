#include "LineMonitor.h"
#include <cstdlib>  // abs() for integer
#include <cmath>    // abs() for float, and fabs()
#include <stdlib.h>

rgb_raw_t rgb_val;

/**
 * コンストラクタ
 * @param colorSensor カラーセンサ
 */
LineMonitor::LineMonitor(const ev3api::ColorSensor& colorSensor)
    : mColorSensor(colorSensor){
}

float LineMonitor::isOnLine_gray()const{
    mColorSensor.getRawColor(rgb_val);
    float gray=0.3*rgb_val.r+0.58*rgb_val.g+0.11*rgb_val.b;
    return gray;
    }
    
rgb_raw_t rgb_raw;

int LineMonitor::getRgbColor() const {
    mColorSensor.getRawColor(rgb_raw);
    float valMax;
    float perBlue = (float)rgb_raw.b/(float)(rgb_raw.r + rgb_raw.g + rgb_raw.b);
    printf("blue %f\t", perBlue);
    if(rgb_raw.r < rgb_raw.g){
        valMax = ((rgb_raw.g < rgb_raw.b)? rgb_raw.g:rgb_raw.b);
    }else{
        valMax = ((rgb_raw.r < rgb_raw.b)? rgb_raw.r:rgb_raw.b);
    }
    if (0.4 < perBlue){
        return 1; // 青
    }
    else{
        return 0;
    }
}
