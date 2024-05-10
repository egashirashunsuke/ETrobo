#include "StraightCtrl.h"

StraightCtrl::StraightCtrl(ev3api::Motor& leftWheel,
                    ev3api::Motor& rightWheel,
                    int direction)
    : mLeftWheel(leftWheel),
      mRightWheel(rightWheel),
      mDireciton(direction) {
}


int StraightCtrl::judge(){
    int ctrl = 1;
    int32_t count1 = mLeftWheel.getCount();
    int32_t count2 = mRightWheel.getCount();
    if (mDireciton == 1){
        ctrl = -1;
    }
    //printf("L:%d R:%d d:%d",count1,count2,count1 - count2);
    if(count1 < count2){
        return (count1 - count2) * ctrl;
    }else if(count1 > count2){
        return (count1 - count2) * ctrl;
    }else{
        return 0;
    }
}

/**
 * 走行に必要なものをリセットする
 */
void StraightCtrl::init() {
    // モータをリセットする
    mLeftWheel.reset();
    mRightWheel.reset();
}
