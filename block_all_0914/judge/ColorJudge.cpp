#include "ColorJudge.h"

ColorJudge::ColorJudge(const ev3api::ColorSensor& colorSensor,colorid_t targetColor)
        :color(colorSensor),
         targetColor(targetColor){}

int colorCode = 0;

bool ColorJudge::judge(){
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
    
    float valMax;
    float perBlue = (float)rgb_raw.b/(float)(rgb_raw.r + rgb_raw.g + rgb_raw.b);
    float perGreen = (float)rgb_raw.g/(float)(rgb_raw.r + rgb_raw.g + rgb_raw.b);
    
    if(rgb_raw.r < rgb_raw.g){
        valMax = ((rgb_raw.g < rgb_raw.b)? rgb_raw.g:rgb_raw.b);
    }else{
        valMax = ((rgb_raw.r < rgb_raw.b)? rgb_raw.r:rgb_raw.b);
    }

    if (120 < rgb_raw.r && rgb_raw.r > rgb_raw.g && rgb_raw.r > rgb_raw.b){
        if (rgb_raw.g < 60){
                //printf("red\n");
            if (colorCode == 5){
                return 5 == targetColor; // 赤
            }else{
                colorCode = 5;
                return false;
            }
            
            
        
        }else{
            if (perBlue < 0.3){
                if(colorCode == 4){
                    return 4 == targetColor; // 黄
                }else{
                    colorCode = 4;
                    return false;
                }
            }else{
                if(colorCode == 7){
                    return 7 == targetColor; // 茶
                }else{
                    colorCode = 7;
                    return false;
                }
                
            }
        
        }
        
    }else if (0.4 < perBlue){
            if(valMax < 100){
                    printf("blue?");
                if(colorCode == 2){
                    return 2 == targetColor; // 青
                    printf("blue!\n");
                }else{
                    colorCode = 2;
                    printf("No\n");
                    return false;
                }
            }else{
                if(colorCode == 6){
                    return 6 == targetColor; // 白
                }else{
                    colorCode = 6;
                    return false;
                }
                
            }
    
    }else if (0.4 < perGreen){
        
        if(colorCode == 3){
            return 3 == targetColor; // 緑
        }else{
            colorCode = 3;
            return false;
        }
    
    }else if (150 < rgb_raw.r && 150 < rgb_raw.g && 150 < rgb_raw.b){
        if(colorCode == 6){
            return 6 == targetColor; // 白
        }else{
            colorCode = 6;
            return false;
        }

    }else if (rgb_raw.r < 100 && rgb_raw.g < 100 && rgb_raw.b < 100){
        if(colorCode == 1){
            return 1 == targetColor; // 黒
        }else{
            colorCode = 1;
            return false;
        }
        
    }else{
        colorCode = 0;
        return 0 == targetColor; // NONE
    
    }
}

void ColorJudge::init(){
}
