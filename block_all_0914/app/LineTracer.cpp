#include "LineTracer.h"
#include <ColorSensor.h>
#include <time.h>
#include <stdlib.h>

const float LineTracer::TARGET_VAL = 70;
int count_blue = 0;
int blue_phase = 0;
int finish_blue = 0;
int change_edge = 0;
int after_blue = 0;
int stop_pid = 0;
int change_pid = 0;
int after_black = 0;
int one_to_two = 0;
int change_run = 0;

static float diff[2];
static float integral;

/**
 * コンストラクタ
 * @param lineMonitor     ライン判定
 * @param walker 走行
 */
LineTracer::LineTracer(const LineMonitor* lineMonitor,
                       Walker* walker,
                       Checker* colorRed)
    : mColorJudgeRed(colorRed),
      mLineMonitor(lineMonitor),
      mWalker(walker){
}

/**
 * ライントレースする
 */

bool LineTracer::run() {
    float sensor_val=mLineMonitor->isOnLine_gray();
    printf("sensorVal=%f\n",sensor_val);
    if(sensor_val > TARGET_VAL){
        float sensor_val_b=(sensor_val-60.0)/1.1;
        sensor_val=60.0+sensor_val_b;
    }
    float pid_num = pid(1.8, 0, 10, sensor_val,TARGET_VAL); //シミュ：6.0 実機：1.5
    if(change_pid == 1){
        pid_num = pid(2.7, 0, 10, sensor_val,TARGET_VAL); //シミュ：6.0 実機：2.5
    }
    //printf("pid_numの値は %f\n",pid_num);

    int direction = calcDirectionL(sensor_val);
    if(change_edge == 1){
        direction = calcDirectionR(sensor_val);
    }
    mWalker->setCommand(labs(pid_num), direction);
    if(stop_pid == 0){
        if(change_run == 1){
        mWalker->runB();
        }else{
        mWalker->run();}
    }
    int check_blue = mLineMonitor->getRgbColor();
    printf("after_blue %d", after_blue);
    if(check_blue == 1){
        count_blue += 1;
        printf("count_blue %d", count_blue);
        printf("detect blue");
        if(blue_phase == 1){//２度目の青検知でエッジ切替
            if(count_blue > 5 &&  count_blue <= 25){
                stop_pid = 1;
                mWalker->run_getter(55,25);
                printf("------aomatagu1------");
            }
            else if(count_blue > 25){
                integral = 0;
                diff[0] = 0;
                diff[1] = 0;
                finish_blue = 1;
                change_edge = 1;
                change_pid = 1;
                stop_pid = 0;
                printf("----change edge!----");
            }
        }
        else if(blue_phase == 2){//３度目の青検知
            if(count_blue > 30){
                finish_blue = 2;
                
            }
        }
        else if(blue_phase == 3){//４度目の青検知
            if(count_blue > 50){
                finish_blue = 3;
            }
        }
        else if(blue_phase == 0){//一度目の青検知でループ侵入
            if(count_blue > 10 &&  count_blue <= 35){
                mWalker->run_getter(60,15);
                printf("------bunnki------");
            }
            else if(count_blue > 35 &&  count_blue <= 70){
                mWalker->run_getter(45,45);
                printf("------chokushin------");
                finish_blue = 1;
                change_pid = 0;
                stop_pid = 0;
            }
        }
    }
    else if(check_blue == 0 && finish_blue == 1){
        after_blue += 1;
        if(after_blue > 300){
            blue_phase += 1;
            count_blue = 0;
            finish_blue = 0;
            after_blue = 0;
        }//1度目の青検知後のカウント処理
    }
    else if(check_blue == 0 && finish_blue == 2){//3度目の青検知終了後エッジ切り替え
        after_blue += 1;
        if(after_blue >= 1 && after_blue < 25){
            stop_pid = 1;
            mWalker->run_getter(10,55);
            printf("------kuromatagu2------");
        }
        else if(after_blue >= 25 && after_blue < 50){
            stop_pid = 1;
            mWalker->run_getter(55,10);
            printf("------kuromatagu2------");
        }
        if(after_blue >= 50){
            integral = 0;
            diff[0] = 0;
            diff[1] = 0;
            after_blue = 0;
            blue_phase += 1;
            count_blue = 0;
            finish_blue = 0;
            change_edge = 0;
            stop_pid = 0;
            change_run = 1;
            printf("----change edge!----");
        }
    }
    else if(check_blue == 0 && finish_blue == 3){//4度目の青検知終了後脱出
        after_blue += 1;
        if(after_blue >= 90 && after_blue < 140){
            stop_pid = 1;
            mWalker->run_getter(55,10);
        }
        else if(after_blue >= 140 && after_blue < 155){
            mWalker->run_getter(35,35);
        }
        else if(after_blue >= 155){
            change_pid = 0;
            stop_pid = 0;
            finish_blue = 4;
            blue_phase += 1;
            count_blue = 0;
            after_blue = 0;
            change_run = 0;
        }
    }
    else if(check_blue == 0 && finish_blue == 4){//脱出後の合流処理
        after_blue += 1;
        if(mLineMonitor->isOnLine_gray() < 25 && after_blue > 400){
            after_black = 1;
            mWalker->run_getter(35,30);
            printf("---------saigo----------");
        }
        else if(mLineMonitor->isOnLine_gray() >= 25 && after_black == 1){
        finish_blue = 5;
        }
    }

    if(mColorJudgeRed->judge() && finish_blue == 5){
        return true;
    }

    return false;
}

/**
 * 走行体の向きを計算する
 * @param isOnLine true:ライン上/false:ライン外
 * @retval RIGHT  ライン上にある場合(右旋回指示)
 * @retval LEFT ライン外にある場合(左旋回指示)
 */
int LineTracer::calcDirectionL(float isOnLine) {
    if (isOnLine < TARGET_VAL - 20) {
        // ライン上にある場合
        return Walker::LEFT;
    } 
    else if (isOnLine > TARGET_VAL + 20) {
        // ライン上にある場合
        return Walker::RIGHT;
    } 
    else {
        return Walker::STRAIGHT;
    }
}

int LineTracer::calcDirectionR(float isOnLine) {
    if (isOnLine < TARGET_VAL) {
        // ライン上にある場合
        return Walker::RIGHT;
    } 
    else if (isOnLine > TARGET_VAL) {
        // ライン上にある場合
        return Walker::LEFT;
    } 
    else {
        return Walker::STRAIGHT;
    }
}

#define DELTA_T 1
//#define KP 2.5 //1.5
//#define KI 0.0
//#define KD 10.0
const int max_pid=210;
const int min_pid=-210;

float LineTracer::pid(float KP, float KI, float KD, float sensor_val,float target_val){
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
