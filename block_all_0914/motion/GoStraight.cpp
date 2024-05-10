#include "GoStraight.h"

// 定数宣言


/**
 * コンストラクタ
 * @param leftWheel  左モータ
 * @param rightWheel 右モータ
 */
GoStraight::GoStraight(ev3api::Motor& leftWheel,
                                 ev3api::Motor& rightWheel,
                                 int pwm)
    : mLeftWheel(leftWheel),
      mRightWheel(rightWheel),
      mPwm(pwm),
      mStraightCtrl(mLeftWheel, mRightWheel, (mPwm < 0) ? 1 : 0){
}

/**
 * 走行する
 */
void GoStraight::run() {
    int ctrlValue = mStraightCtrl.judge();
    // 左右モータに回転を指示する
    int rightPWM = mPwm;
    int leftPWM = mPwm;
    if (ctrlValue > 0) {
        leftPWM -= (ctrlValue/10 + 2); 
    } else if (ctrlValue < 0) {
        rightPWM -= ((ctrlValue * -1)/10 + 2); 
    }
    printf("   LPWM:%d,RPWM:%d  , ctrlVal:%d\n",leftPWM,rightPWM,ctrlValue);
    mRightWheel.setPWM(rightPWM);
    mLeftWheel.setPWM(leftPWM);
}

/**
 * 走行に必要なものをリセットする
 */
void GoStraight::init() {
    // モータをリセットする
    mLeftWheel.reset();
    mRightWheel.reset();
}


