#include "Scene.h"


//誤検知する可能性があるから、変数を設定してやる方が良いかも

/**
 * コンストラクタ
 * @param motion
 */
Scene::Scene(Motion* motion,
                Checker* checker)
    :mMotion(motion),
    mChecker(checker),
    mState(INIT) {
}



/**
 * 
 */
bool Scene::run() {
    switch (mState) {
    case INIT:
        //printf("SceneのINITケース\n");
        execInit();
        return false;
        break;
    case RUN:
        //printf("SceneのRUNケース\n");
        if(execRun()){
            return true;
        }else{
            return false;
        }
        break;
    default:
        return false;
        break;
    }
}

void Scene::execInit() {
    mMotion->init();
    mChecker->init();
    mState=RUN;
    //printf("動作と動作移行判定を初期化\n");
}

bool Scene::execRun() {
    mMotion->run();
    //mTurnLeft->init();
    //mTurnLeft->run();
    //mChecker->judge(); 
    if(mChecker->judge()){//判定がtrueの時
        //printf("い\n");
        //連続で「動作」、「動作移行判定」を使用する場合に備えて初期化しておく
        mMotion->init();
        mChecker->init();
        mState=INIT;
        return true;
    }else{
        return false;
    }
    //printf("い\n");
}
