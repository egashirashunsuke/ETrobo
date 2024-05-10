#include "Turn.h"


/**
 * コンストラクタ
 * @param leftWheel  左モータ
 * @param rightWheel 右モータ
 * *@param turn 方向
 */
Turn::Turn(ev3api::Motor& leftWheel,
                                 ev3api::Motor& rightWheel,
                                 int turn)
    : mLeftWheel(leftWheel),
      mRightWheel(rightWheel),
      mTurn(turn){
}

/**
 * 走行する
 */
void Turn::run() {
    // 左右モータに回転を指示する
    int rightPWM = 0;
    int leftPWM = 0;
    
    if(mTurn == 0) {
        rightPWM = 70;
        leftPWM = 0;
    } else if(mTurn == 1) {
        rightPWM = 0;
        leftPWM = 70;
    } else{
    }
    mRightWheel.setPWM(rightPWM);
    mLeftWheel.setPWM(leftPWM);
}

/**
 * 走行に必要なものをリセットする
 */
void Turn::init() {
    mLeftWheel.reset();
    mRightWheel.reset();
}



