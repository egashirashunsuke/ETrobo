#include "Walker.h"
#include "LineTracer.h"


// 定数宣言
const int Walker::INITIAL_SPEED = 45;  //初期速度

const int Walker::RIGHT  = 0;     // 左方向
const int Walker::LEFT   = 1;     // 右方向
const int Walker::STRAIGHT = 2;   // 前方向

/**
 * コンストラクタ
 * @param leftWheel  左モータ
 * @param rightWheel 右モータ
 */
Walker::Walker(ev3api::Motor& leftWheel, ev3api::Motor& rightWheel)
    : mLeftWheel(leftWheel),
      mRightWheel(rightWheel),
      mForward(INITIAL_SPEED),
      mTurn(RIGHT) {
}

/**
 * 走行する
 */

void Walker::run() {
    // 左右モータに回転を指示する
    printf("right_%d\n",ev3_motor_get_counts(EV3_PORT_B));
    int rightPWM = 0;
    int leftPWM = 0;
    if(mTurn == RIGHT) {
        rightPWM = 35;
        leftPWM = mForward/3+35;
        if(leftPWM>70){
            rightPWM=rightPWM-25;
            leftPWM=leftPWM-25;
        }
        else if(leftPWM>60){
            rightPWM=rightPWM-15;
            leftPWM=leftPWM-15;
            }
        //printf("RIGHT\n");
    } else if(mTurn == LEFT) {
        rightPWM = mForward/3+35;
        leftPWM = 35;
        if(rightPWM>70){
            rightPWM=rightPWM-25;
            leftPWM=leftPWM-25;
        }
        else if(rightPWM>60){
            rightPWM=rightPWM-15;
            leftPWM=leftPWM-15;
            }
        printf("LEFT\n");
      } else{
        rightPWM = 50;
        leftPWM = 50;
        printf("slowSTRAIGHTslow\n");}
    //printf("THE LEFTWHEEL IS %d",leftPWM);
    //printf("THE RIGHTWHEEL IS %d\n",rightPWM);
    mRightWheel.setPWM(rightPWM);
    mLeftWheel.setPWM(leftPWM);
}

void Walker::runB() {
    // 左右モータに回転を指示する
    printf("right_%d\n",ev3_motor_get_counts(EV3_PORT_B));
    int rightPWM = 0;
    int leftPWM = 0;
    if(mTurn == RIGHT) {
        rightPWM = 35;
        leftPWM = mForward/3+35;
        if(leftPWM>70){
            rightPWM=rightPWM-25;
            leftPWM=leftPWM-25;
        }
        else if(leftPWM>60){
            rightPWM=rightPWM-15;
            leftPWM=leftPWM-15;
            }
        printf("RIGHT\n");
    } else if(mTurn == LEFT) {
        rightPWM = mForward/3+35;
        leftPWM = 35;
        if(rightPWM>70){
            rightPWM=rightPWM-25;
            leftPWM=leftPWM-25;
        }
        else if(rightPWM>60){
            rightPWM=rightPWM-15;
            leftPWM=leftPWM-15;
            }
        printf("LEFT\n");
      } else {
        rightPWM = 35;
        leftPWM = 35;
        printf("slowSTRAIGHTslow\n");}
    //printf("THE LEFTWHEEL IS %d",leftPWM);
    //printf("THE RIGHTWHEEL IS %d\n",rightPWM);
    mRightWheel.setPWM(rightPWM);
    mLeftWheel.setPWM(leftPWM);
}

void Walker::run_getter(int left,int right) {
    // 左右モータに回転を指示する
    int rightPWM = right;
    int leftPWM = left;
    mRightWheel.setPWM(rightPWM);
    mLeftWheel.setPWM(leftPWM);
}

/**
 * 走行に必要なものをリセットする
 */
void Walker::init() {
    // モータをリセットする
    mLeftWheel.reset();
    mRightWheel.reset();
}

/**
 * PWM値を設定する
 * @param forward 前進値
 * @param turn    旋回方向
 */
void Walker::setCommand(int forward, int turn) {
    mForward = forward;
    mTurn    = turn;
}
