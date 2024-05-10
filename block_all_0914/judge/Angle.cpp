#include "Angle.h"


/**
 * コンストラクタ
 * @param 
 */
Angle::Angle(ev3api::Motor& leftWheel,
                    ev3api::Motor& rightWheel,
                    int targetangle,
                    int turn)
    : mLeftWheel(leftWheel),
      mRightWheel(rightWheel),
      mTargetAngle(targetangle),
      mTurn(turn) {
}
//mTurn
//1right
//0left
/**
 * 判定する
 */
bool Angle::judge() {
  int32_t count1 = mLeftWheel.getCount();
  int32_t count2 = mRightWheel.getCount();
  if(mTurn == 0){
      if (mTargetAngle < count2){
      return true;
    }else{
      return false;
    }
  }else if (mTurn == 1){
    if (mTargetAngle < count1){
      return true;
    }else{
      return false;
    }
  }
  
}

/**
 * 走行に必要なものをリセットする
 */
void Angle::init() {
    // モータをリセットする
    mLeftWheel.reset();
    mRightWheel.reset();
}


