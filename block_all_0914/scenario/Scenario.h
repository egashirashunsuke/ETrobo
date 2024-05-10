#ifndef EV3_SCENARIO_SCENARIO_H_
#define EV3_SCENARIO_SCENARIO_H_

#include "Scene.h"

class Scenario {
public:
    Scenario(int patern,int scenarioNumber,Scene* scene1,
                                            Scene* scene2,
                                            Scene* scene3,
                                            Scene* scene4,
                                            Scene* scene5,
                                            Scene* scene6,
                                            Scene* scene7,
                                            Scene* scene8,
                                            Scene* scene9,
                                            Scene* scene10,
                                            Scene* scene11,
                                            Scene* scene12,
                                            Scene* scene13,
                                            Scene* scene14,
                                            Scene* scene15,
                                            Scene* scene16,
                                            Scene* scene17,
                                            Scene* scene18,
                                            Scene* scene19,
                                            Scene* scene20,
                                            Scene* scene21,
                                            Scene* scene22,
                                            Scene* scene23,
                                            Scene* scene24,
                                            Scene* scene25,
                                            Scene* scene26,
                                            Scene* scene27,
                                            Scene* scene28,
                                            Scene* scene29,
                                            Scene* scene30,
                                            Scene* scene31,
                                            Scene* scene32,
                                            Scene* scene33,
                                            Scene* scene34,
                                            Scene* scene35,
                                            Scene* scene36,
                                            Scene* scene37,
                                            Scene* scene38,
                                            Scene* scene39,
                                            Scene* scene40,
                                            Scene* scene41,
                                            Scene* scene42,
                                            Scene* scene43,
                                            Scene* scene44,
                                            Scene* scene45,
                                            Scene* scene46,
                                            Scene* scene47,
                                            Scene* scene48,
                                            Scene* scene49,
                                            Scene* scene50,
                                            Scene* scene51,
                                            Scene* scene52,
                                            Scene* scene53,
                                            Scene* scene54,
                                            Scene* scene55,
                                            Scene* scene56,
                                            Scene* scene57,
                                            Scene* scene58,
                                            Scene* scene59,
                                            Scene* scene60,
                                            Scene* scene61,
                                            Scene* scene62,
                                            Scene* scene63,
                                            Scene* scene64,
                                            Scene* scene65,
                                            Scene* scene66,
                                            Scene* scene67,
                                            Scene* scene68);

    bool run();


    Scene* mArmDown_ArmJudgeDown;
    Scene* mLineTrace_ColorJudgeRed;
    Scene* mTurnRight_AngleRight1;
    Scene* mGoStraight1_ColorJudgeBlack;
    Scene* mGoStraightBack_DistanceBack1;
    Scene* mTurnLeft_AngleLeft1;
    Scene* mLineTrace_ColorJudgeBlue;
    Scene* mGoStraight2_Distance1;
    Scene* mTurnRight_AngleRight2;
    Scene* mArmUp_ArmJudgeUp;
    Scene* mTurnLeft_AngleLeft2;
    Scene* mTurnRight_AngleRight3;
    Scene* mGoStraightBack_DistanceBack2;
    Scene* mGoStraight3_Distance2;
    Scene* mTurnLeft_AngleLeft3;
    Scene* mGoStraight1_Distance3;
    Scene* mGoStraightBack_DistanceBack3;
    Scene* mLineTrace_ColorJudgeGreen;
    Scene* mLineTrace_ColorJudgeYellow;
    Scene* mTurnLeft_AngleLeft4;
    Scene* mTurnLeft_AngleLeft5;
    Scene* mGoStraight3_Distance4;
    Scene* mTurnLeft_AngleLeft6;
    Scene* mTurnRight_AngleRight4;
    Scene* mGoStraight1_Distance5;
    Scene* mTurnLeft_AngleLeft7;
    Scene* mTurnRight_AngleRight5;
    Scene* mGoStraight3_Distance6;
    Scene* mTurnLeft_AngleLeft8;
    Scene* mTurnLeft_ColorJudgeBlack;
    Scene* mGoStraight1_Distance7;
    Scene* mGoStraight1_Distance8;
    Scene* mTurnLeft_AngleLeft9;
    Scene* mGoStraight3_Distance9;
    Scene* mTurnLeft_AngleLeft10;
    Scene* mGoStraightBack_DistanceBack4;
    Scene* mTurnRight_AngleRight6;
    Scene* mGoStraightBack_DistanceBack5;
    Scene* mTurnRight_AngleRight7;
    Scene* mTurnRight_AngleRight8;
    Scene* mTurnRight_AngleRight9;
    Scene* mTurnRight_AngleRight10;
    Scene* mTurnLeft_AngleLeft11;
    Scene* mTurnLeft_AngleLeft12;
    Scene* mTurnLeft_AngleLeft13;
    Scene* mTurnLeft_AngleLeft14;
    Scene* mTurnLeft_AngleLeft15;
    Scene* mTurnLeft_AngleLeft16;
    Scene* mGoStraight3_Distance10;
    Scene* mGoStraight3_Distance11;
    Scene* mGoStraight1_Distance12;
    Scene* mGoStraight1_Distance13;
    Scene* mGoStraight3_Distance14;
    Scene* mGoStraight3_Distance15;
    Scene* mTurnRight_AngleRight11;
    Scene* mGoStraight2_Distance16;
    Scene* mGoStraight2_Distance17;
    Scene* mGoStraight2_Distance18;
    Scene* mGoStraightBack_DistanceBack6;
    Scene* mGoStraightBack_DistanceBack7;
    Scene* mGoStraightBack_DistanceBack8;
    Scene* mGoStraightBack_DistanceBack9;
    Scene* mGoStraightBack_DistanceBack10;
    Scene* mGoStraightBack_DistanceBack11;
    Scene* mGoStraightBack_DistanceBack12;
    Scene* mGoStraightBack_DistanceBack13;
    Scene* mGoStraightBack_DistanceBack14;
    Scene* mTurnRight_ColorJudgeBlack;


private:
    int mPatern;
    int mScenarioNumber;
    

};

#endif  
