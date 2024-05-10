#include "ScenarioManager.h"
#include <stdlib.h>

//パターンとブロックの色に応じて、シナリオを呼び出すクラス

int scenarioNumber=1;
int pass3 = 0;
/**
 * コンストラクタ
 * @param scenario
 */
ScenarioManager::ScenarioManager(Checker* colorRed,Checker* colorBlue,Scenario* scenario1,
                                                                                    Scenario* scenario2,
                                                                                    Scenario* scenario3,
                                                                                    Scenario* scenario4,
                                                                                    Scenario* scenario5)
    :mColorJudgeRed(colorRed),
    mColorJudgeBlue(colorBlue),
    mScenario1(scenario1),
    mScenario2(scenario2),
    mScenario3(scenario3),
    mScenario4(scenario4),
    mScenario5(scenario5){
}


bool ScenarioManager::run() {
        if (scenarioNumber == 1){//一個目のブロックを見つけるまで
            //printf("scenario1\n");
           if (mScenario1->run()){
               scenarioNumber++;
           }
           return false;
        }else if (scenarioNumber == 2){//赤青判定
            //printf("colorCheak\n");
            pass3 += 1;
            printf("test_pass3:%d\n",pass3);
            if (mColorJudgeRed->judge() || pass3 >= 300){
                scenarioNumber++;
                pass3 = 0;
            }
            if (mColorJudgeBlue->judge()){
                scenarioNumber+=2;
                pass3 = 0;
            }
            /*
            if (mColorJudgeRed->judge()){
                scenarioNumber+=2;
            }
            if (mColorJudgeBlue->judge()){
                scenarioNumber++;
            }*/
            return false;
        }else if (scenarioNumber == 3){//一個目からゴール
            //printf("scenario2\n");
            if (mScenario2->run()){
                scenarioNumber++;
                return true;
            }
            return false;
            
        }else if (scenarioNumber == 4){//一個目から二個目
            //printf("scenario3\n");
            if (mScenario3->run()){
                scenarioNumber++;
            }
            return false;
                
        }else if (scenarioNumber == 5){
            pass3 += 1;
            printf("test_pass3:%d\n",pass3);
            //printf("colorCheak\n");
            if (mColorJudgeRed->judge() || pass3 >= 300){
                scenarioNumber++;
                pass3 = 0;
            }
            if (mColorJudgeBlue->judge()){
                scenarioNumber+=2;
                pass3 = 0;
            }
            /*
            if (mColorJudgeRed->judge()){
                scenarioNumber+=2;
            }
            if (mColorJudgeBlue->judge()){
                scenarioNumber++;
            }*/
            return false;
        }else if (scenarioNumber == 6){//二個目からゴール
            //printf("scenario4\n");
            if (mScenario4->run()){
                    scenarioNumber++;
                    return true;
            }
            return false;
                
        }else if (scenarioNumber == 7){//三個目をとってゴール
            //printf("scenario5\n");
            if (mScenario5->run()){
                    scenarioNumber++;
                    return true;
                }
            return false;
                
        }
    
}





