#include "LineTrace.h"

#include <ColorSensor.h>
#include <time.h>
#include <stdlib.h>
// 定数宣言

const float LineTrace::TARGET_VAL = 70;

/**
 * コンストラクタ
 * @param leftWheel  左モータ
 * @param rightWheel 右モータ
 */
LineTrace::LineTrace(const LineMonitor* lineMonitor,
                       Walker* walker)
    : mLineMonitor(lineMonitor),
      mWalker(walker){
}

/**
 * 走行する
 */
void LineTrace::run() {
    float sensor_val=mLineMonitor->isOnLine_gray();
    //printf("sensorVal=%f\n",sensor_val);

        if(sensor_val > TARGET_VAL){
            float sensor_val_b=(sensor_val-60.0)/1.1;
            sensor_val=60.0+sensor_val_b;}
        float pid_num = pid(sensor_val,TARGET_VAL);
        //printf("pid_numの値は %f\n",pid_num);
        int direction = calcDirection(sensor_val);
       
        mWalker->setCommand(labs(pid_num), direction);

        if(sensor_val>130){
            mWalker->run_getter(55,5);
        }
        else{
        mWalker->run();
        }    
    /*}*/
}

/**
 * 走行体の向きを計算する
 * @param isOnLine true:ライン上/false:ライン外
 * @retval RIGHT  ライン上にある場合(右旋回指示)
 * @retval LEFT ライン外にある場合(左旋回指示)
 */
int LineTrace::calcDirection(float isOnLine) {
    if (isOnLine < TARGET_VAL) {
        // ライン上にある場合
        return Walker::LEFT;
    } 
    else if(isOnLine == TARGET_VAL){
        return Walker::STRAIGHT;
    }
    else {
        // ライン外にある場合
        return Walker::RIGHT;
    }
}

#define DELTA_T 1
#define KP 3.0 //1.5
#define KI 0.0
#define KD 10.0
static float diff[2];
static float integral;
const int max_pid=210;
const int min_pid=-210;

float LineTrace::pid(float sensor_val,float target_val){
    float p,i,d;
    diff[0]=diff[1];
    diff[1]=sensor_val-target_val;
    integral+=(diff[1]+diff[0])/2.0*DELTA_T;

    p=KP*diff[1];
    i=KI*integral;
    //printf("%d\n",i);
    d=KD*(diff[1]-diff[0])/DELTA_T;
    if(p+i+d>=max_pid){
        return max_pid;
    }
    else if(p+i+d<=min_pid){
        return min_pid;
    }
    else{
        return p+i+d;
    }
    //return<-曲がり具合を示す.
}

/**
 * 走行に必要なものをリセットする
 */
void LineTrace::init() {
    // モータをリセットする
    mWalker->init();
    
}


