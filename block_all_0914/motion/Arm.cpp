#include "Arm.h"

// 定数宣言


/**
 * コンストラクタ
 * @param leftWheel  左モータ
 * @param rightWheel 右モータ
 */
Arm::Arm(ev3api::Motor& Arm,int turn)
    : mArm(Arm),
      mTurn(turn){
}

void Arm::run() {
    int PWM = 0;
    
    if(mTurn == 0) {//アームをあげる
        PWM = -150;
    } else if(mTurn == 1) {//アームを下げる
        PWM = +150;
    } 
    
    mArm.setPWM(PWM);
}

/**
 * 走行に必要なものをリセットする
 */
void Arm::init() {
    mArm.reset();
}
