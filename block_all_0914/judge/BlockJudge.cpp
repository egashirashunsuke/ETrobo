#include "BlockJudge.h"

BlockJudge::BlockJudge(const ev3api::ColorSensor& colorSensor,float blockDist)
        :color(colorSensor),
         blockDist(blockDist){}

bool BlockJudge::judge(){
    /*
    mColorSensor.getRawColor(rgb_raw);

    return rgb_raw.r;  //茶色がとれれば良いので赤のみを返す
    */
    
    
    /* 参考: https://qiita.com/koushiro/items/97d08cf3d863d6f81f2e
    白	165-175	180-200	200-215
    黒  	<20     <20	    <20
        <100	<100	<100	
    板	150-160	140-150	130-140

    赤	120-140	25-35	35-50
raw
    緑	30-40	70-90	50-65

    黄	160-170	150-160	90-100

    青  	10-20	40-50	80-90
    */
    
    color.getRawColor(rgb_raw);
    float gray=0.3*rgb_raw.r+0.58*rgb_raw.g+0.11*rgb_raw.b;
    
    printf("%f",gray);

    return (gray > blockDist);
}

void BlockJudge::init(){
}