/******************************************************************************
 *  RandomWalker.cpp (for LEGO Mindstorms EV3)
 *  Created on: 2015/02/07
 *  Implementation of the Class RandomWalker
 *  Author: Kenya Yabe
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/


#include "Clock.h"
#include <stdlib.h>
#include "RandomWalker.h"

// 定数宣言


/**
 * コンストラクタ
 * @param starter         スタータ  
 * @param scenario  　シナリオ
 */
RandomWalker::RandomWalker(const Starter* starter,
                           LineTracer* lineTracer,
                           ScenarioManager* scenariomanager)
    : mScenarioManager(scenariomanager),
      mStarter(starter),
      mLineTracer(lineTracer),
      mState(UNDEFINED) {
    ev3api::Clock* clock = new ev3api::Clock();

    srand(clock->now());  // 乱数をリセットする

    delete clock;
}

/**
 * ロボコンの難所ごとのステートメント
 */
void RandomWalker::run() {
    switch (mState) {
    case UNDEFINED:
        execUndefined();
        break;
    case WAITING_FOR_START:
        execWaitingForStart();
        break;
    case LINE_TRACING:
        execLineTracing();
        break;
    case BLOCK:
        execBlock();
        break;
    case FINISH:
        break;
    default:
        break;
    }
}




/**
 * 未定義状態の処理
 */
void RandomWalker::execUndefined() {
    mState = WAITING_FOR_START;
}

/**
 * 開始待ち状態の処理
 */
void RandomWalker::execWaitingForStart() {
    if (mStarter->isPushed()) {
        mState = LINE_TRACING;

    }
}

void RandomWalker::execLineTracing() {
        if(mLineTracer->run()){
            mState = BLOCK;
        }
}

/**
 * ブロックの処理
 */
void RandomWalker::execBlock() {
    //printf("ブロックの処理を開始する\n");
    if (mScenarioManager->run()){
        printf("finish\n");
        mState = FINISH;
    }
}


