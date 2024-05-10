#include "Distance.h"


/**
 * コンストラクタ
 * @param gyrosensor ジャイロセンサー
 */
Distance::Distance(ev3api::Motor& leftWheel,
                    ev3api::Motor& rightWheel,
                    int32_t targetangle,
                    int direction)
    : mLeftWheel(leftWheel),
      mRightWheel(rightWheel),
      mTargetAngle(targetangle),
      mDireciton(direction) {
}

//0mae
//1usiro
/**
 * 判定する
 */
bool Distance::judge() {
  int32_t count1 = mLeftWheel.getCount();
  int32_t count2 = mRightWheel.getCount();
  if (mDireciton == 0){
    if(count1 >= mTargetAngle){
      return true;
    }else{
    return false;
    }
  }else if (mDireciton == 1){
    if(count1 <= mTargetAngle){
      return true;
    }else{
      return false;
    }
  }
}

/**
 * 走行に必要なものをリセットする
 */
void Distance::init() {
    // モータをリセットする
    mLeftWheel.reset();
    mRightWheel.reset();
}


