/******************************************************************************
 *  RandomWalker.h (for LEGO Mindstorms EV3)
 *  Created on: 2015/02/07
 *  Implementation of the Class RandomWalker
 *  Author: Kenya Yabe
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#ifndef EV3_APP_RANDOMWALKER_H_
#define EV3_APP_RANDOMWALKER_H_

#include "Starter.h"
#include "ScenarioManager.h"
#include "LineTracer.h"

class RandomWalker {
public:
    RandomWalker(const Starter* starter,
                 LineTracer* lineTracer,
                 ScenarioManager* scenariomanager);

    void run();

private:
    enum State {
        UNDEFINED,
        WAITING_FOR_START,
        BLOCK,
        LINE_TRACING,
        FINISH
    };

    static const int MIN_TIME;
    static const int MAX_TIME;


    LineTracer* mLineTracer;
    ScenarioManager* mScenarioManager;
    const Starter* mStarter;
    State mState;

    void modeChangeAction();
    void execUndefined();
    void execLineTracing();
    void execWaitingForStart();
    void execBlock();
};

#endif  // EV3_APP_RANDOMWALKER_H_
