#include "Scenario.h"


//パターンとシナリオの番号に応じて、シーンを呼び出すクラス


//シーンのステートを保存する変数
int blockState = 1;


//シナリオ番号
/**
 * コンストラクタ
 * @param scene
 */
Scenario::Scenario(int patern,int scenarioNumber,Scene* scene1,
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
                                                    Scene* scene68)
    :mPatern(patern),
    mScenarioNumber(scenarioNumber),
    mArmDown_ArmJudgeDown(scene1),
    mLineTrace_ColorJudgeRed(scene2),
    mTurnRight_AngleRight1(scene3),
    mGoStraight1_ColorJudgeBlack(scene4),
    mGoStraightBack_DistanceBack1(scene5),
    mTurnLeft_AngleLeft1(scene6),
    mLineTrace_ColorJudgeBlue(scene7),
    mGoStraight2_Distance1(scene8),
    mTurnRight_AngleRight2(scene9),
    mArmUp_ArmJudgeUp(scene10),
    mTurnLeft_AngleLeft2(scene11),
    mTurnRight_AngleRight3(scene12),
    mGoStraightBack_DistanceBack2(scene13),
    mGoStraight3_Distance2(scene14),
    mTurnLeft_AngleLeft3(scene15),
    mGoStraight1_Distance3(scene16),
    mGoStraightBack_DistanceBack3(scene17),
    mLineTrace_ColorJudgeGreen(scene18),
    mLineTrace_ColorJudgeYellow(scene19),
    mTurnLeft_AngleLeft4(scene20),
    mTurnLeft_AngleLeft5(scene21),
    mGoStraight3_Distance4(scene22),
    mTurnLeft_AngleLeft6(scene23),
    mTurnRight_AngleRight4(scene24),
    mGoStraight1_Distance5(scene25),
    mTurnLeft_AngleLeft7(scene26),
    mTurnRight_AngleRight5(scene27),
    mGoStraight3_Distance6(scene28),
    mTurnLeft_AngleLeft8(scene29),
    mTurnLeft_ColorJudgeBlack(scene30),
    mGoStraight1_Distance7(scene31),
    mGoStraight1_Distance8(scene32),
    mTurnLeft_AngleLeft9(scene33),
    mGoStraight3_Distance9(scene34),
    mTurnLeft_AngleLeft10(scene35),
    mGoStraightBack_DistanceBack4(scene36),
    mTurnRight_AngleRight6(scene37),
    mGoStraightBack_DistanceBack5(scene38),
    mTurnRight_AngleRight7(scene39),
    mTurnRight_AngleRight8(scene40),
    mTurnRight_AngleRight9(scene41),
    mTurnRight_AngleRight10(scene42),
    mTurnLeft_AngleLeft11(scene43),
    mTurnLeft_AngleLeft12(scene44),
    mTurnLeft_AngleLeft13(scene45),
    mTurnLeft_AngleLeft14(scene46),
    mTurnLeft_AngleLeft15(scene47),
    mTurnLeft_AngleLeft16(scene48),
    mGoStraight3_Distance10(scene49),
    mGoStraight3_Distance11(scene50),
    mGoStraight1_Distance12(scene51),
    mGoStraight1_Distance13(scene52),
    mGoStraight3_Distance14(scene53),
    mGoStraight3_Distance15(scene54),
    mTurnRight_AngleRight11(scene55),
    mGoStraight2_Distance16(scene56),
    mGoStraight2_Distance17(scene57),
    mGoStraight2_Distance18(scene58),
    mGoStraightBack_DistanceBack6(scene59),
    mGoStraightBack_DistanceBack7(scene60),
    mGoStraightBack_DistanceBack8(scene61),
    mGoStraightBack_DistanceBack9(scene62),
    mGoStraightBack_DistanceBack10(scene63),
    mGoStraightBack_DistanceBack11(scene64),
    mGoStraightBack_DistanceBack12(scene65),
    mGoStraightBack_DistanceBack13(scene66),
    mGoStraightBack_DistanceBack14(scene67),
    mTurnRight_ColorJudgeBlack(scene68){
}






bool Scenario::run() {//パターンごとに分け、シナリオ番号ごとにも分ける
    if (mPatern == 1){//パターン1の場合
        if (mScenarioNumber == 1){//パターン1シナリオ1の場合
            if (blockState == 1){
                if(mArmDown_ArmJudgeDown->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 2){
                if(mLineTrace_ColorJudgeRed->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 3){
                if(mTurnRight_AngleRight1->run()){//右旋回、指定角度右1
                    blockState++;
                }
                return false;
            }else if (blockState == 4){
                if(mGoStraight1_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 5){
                if(mGoStraightBack_DistanceBack1->run()){//後退、距離後退1
                    blockState++;
                }
                    return false;
            }else if (blockState == 6){
                if(mTurnLeft_AngleLeft1->run()){//左旋回、指定角度左1
                    blockState++;
                }
                    return false;
            }else if (blockState == 7){
                if(mLineTrace_ColorJudgeBlue->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 8){
                if(mGoStraight2_Distance1->run()){//直進2、指定距離1
                    blockState++;
                }
                    return false;
                
            }else if (blockState == 9){
                if(mTurnRight_AngleRight2->run()){//右旋回、指定角度右2
                    blockState++;
                }
                    return false;
            }else if (blockState == 10){
                if(mLineTrace_ColorJudgeBlue->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 11){
                if(mArmUp_ArmJudgeUp->run()){
                    blockState=1;
                    return true;
                }
                    return false;
            }
        }else if (mScenarioNumber == 2){//パターン1シナリオ2の場合(一個目からゴールまで)
            if (blockState == 1){
                if(mArmDown_ArmJudgeDown->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 2){
                if(mGoStraight3_Distance2->run()){//直進1、指定距離2
                    blockState++;
                }
                return false;
            }else if (blockState == 3){
                if(mTurnLeft_AngleLeft3->run()){//左旋回、指定角度左3
                    blockState++;
                }
                    return false;
            }else if (blockState == 4){
                if(mGoStraight1_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 5){
                if(mGoStraight2_Distance1->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 6){
                if(mTurnLeft_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 7){
                if(mTurnRight_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 8){
                if(mLineTrace_ColorJudgeBlue->run()){
                    blockState=0;
                    return true;
                }
                    return false;
            }
        }else if (mScenarioNumber == 3){//パターン1シナリオ3の場合(一個目から二個目まで)
            if (blockState == 1){
                if(mArmDown_ArmJudgeDown->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 2){
                if(mGoStraight1_Distance3->run()){//直進、指定距離3
                    blockState++;
                    return false;
                }
                return false;
            }else if (blockState == 3){
                if(mGoStraightBack_DistanceBack3->run()){//後退、指定距離後ろ3
                    blockState++;
                }
                return false;
            }else if (blockState == 4){
                if(mTurnLeft_AngleLeft4->run()){//左旋回、指定角度左4
                    blockState++;
                }
                return false;
            }else if (blockState == 5){
                if(mLineTrace_ColorJudgeRed->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 6){
                if(mGoStraight1_Distance3->run()){//直進1、指定距離3
                    blockState++;
                }
                return false;
            }else if (blockState == 7){
                if(mLineTrace_ColorJudgeRed->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 8){
                if(mGoStraightBack_DistanceBack6->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 9){
                if(mTurnLeft_AngleLeft2->run()){//左旋回、指定角度左2
                    blockState++;
                }
                return false;
            }else if (blockState == 10){
                if(mLineTrace_ColorJudgeRed->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 11){
                if(mArmUp_ArmJudgeUp->run()){
                    blockState=1;
                    return true;
                }
                    return false;
            } 
        }else if (mScenarioNumber == 4){//パターン1シナリオ4の場合(二個目からゴールまで)
            if (blockState == 1){
                printf("scene1");
                if(mArmDown_ArmJudgeDown->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 2){
                if(mGoStraight1_Distance8->run()){//直進1、指定距離8
                    blockState++;
                }
                return false;
            }else if (blockState == 3){
                if(mTurnLeft_AngleLeft5->run()){//左旋回、指定角度左5
                    blockState++;
                }
                return false;
            }else if (blockState == 4){
                if(mGoStraight3_Distance4->run()){//直進3、指定距離4
                    blockState++;
                }
                    return false;
            }else if (blockState == 5){
                if(mTurnLeft_AngleLeft6->run()){//左旋回、指定角度左6
                    blockState++;
                }
                    return false;
            }else if (blockState == 6){
                if(mGoStraight1_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 7){
                if(mGoStraight2_Distance1->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 8){
                if(mTurnLeft_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 9){
                if(mTurnRight_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 10){
                if(mLineTrace_ColorJudgeBlue->run()){
                    blockState=1;
                    return true;
                }
                    return false;
            }
            
        }else if (mScenarioNumber == 5){//パターン1シナリオ5の場合(三個目からゴールまで)
            if (blockState == 1){
                if(mArmDown_ArmJudgeDown->run()){
                    blockState++;
                }
                return false;
            }
            if (blockState == 2){
                if(mGoStraight1_Distance3->run()){//直進1、指定距離3
                    blockState++;
                    return false;
                }
                return false;
            }else if (blockState == 3){
                if(mGoStraightBack_DistanceBack9->run()){//後退、指定距離後ろ3
                    blockState++;
                }
                return false;
            }else if (blockState == 4){
                if(mTurnLeft_AngleLeft4->run()){//左旋回、指定角度左4
                    blockState++;
                }
                return false;
            }else if (blockState == 5){
                if(mLineTrace_ColorJudgeRed->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 6){
                if(mGoStraightBack_DistanceBack6->run()){//後退、指定距離後ろ2
                    blockState++;
                }
                return false;
            }else if (blockState == 7){
                if(mTurnLeft_AngleLeft2->run()){//左旋回、指定角度左2
                    blockState++;
                }
                return false;
            }else if (blockState == 8){
                if(mLineTrace_ColorJudgeRed->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 9){
                if(mGoStraight1_Distance7->run()){//直進、指定距離7
                    blockState++;
                }
                return false;
            }else if (blockState == 10){
                if(mLineTrace_ColorJudgeYellow->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 11){
                if(mGoStraightBack_DistanceBack7->run()){//後退、指定距離後ろ2
                    blockState++;
                }
                return false;
            }else if (blockState == 12){
                if(mTurnLeft_AngleLeft2->run()){//左旋回、指定角度左2
                    blockState++;
                }
                return false;
            }else if (blockState == 13){
                if(mLineTrace_ColorJudgeYellow->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 14){
                if(mGoStraight2_Distance18->run()){//直進、指定距離1
                    blockState++;
                }
                return false;
            }else if (blockState == 15){
                if(mTurnRight_AngleRight2->run()){//右旋回、指定角度右2
                    blockState++;
                }
                return false;
            }else if (blockState == 16){
                if(mLineTrace_ColorJudgeYellow->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 17){
                if(mTurnRight_AngleRight4->run()){//右旋回、指定角度右4
                    blockState++;
                }
                return false;
            }else if (blockState == 18){
                if(mGoStraight1_Distance5->run()){//直進1、指定距離5
                    blockState++;
                }
                return false;
            }else if (blockState == 19){
                if(mTurnLeft_AngleLeft7->run()){//左旋回、指定角度左7
                    blockState++;
                }
                return false;
            }else if (blockState == 20){
                if(mGoStraight1_ColorJudgeBlack->run()){
                    blockState+=1;
                }
                    return false;
            }else if (blockState == 21){
                if(mGoStraight2_Distance1->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 22){
                if(mTurnLeft_ColorJudgeBlack->run()){
                    blockState+=1;
                }
                    return false;
            }else if (blockState == 23){
                if(mTurnRight_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 24){
                if(mLineTrace_ColorJudgeBlue->run()){
                    blockState=1;
                    return true;
                }
                    return false;
            }
            
        }
    }else if (mPatern == 2){//-------------パターン2------------------------------------------------------------------------------------------
        if (mScenarioNumber == 1){//パターン2シナリオ1の場合
            if (blockState == 1){
                printf("ArmDown\n");
                if(mArmDown_ArmJudgeDown->run()){//アーム下げ
                    blockState++;
                }
                return false;
            }else if (blockState == 2){
                printf("ArmDown\n");
                if(mLineTrace_ColorJudgeRed->run()){//赤までトレース
                    blockState++;
                }
                return false;
            }else if (blockState == 3){
                printf("InitTurn\n");
                if(mTurnRight_AngleRight1->run()){//侵入曲がる
                    blockState++;
                }
                return false;
            }else if (blockState == 4){
                printf("GostBlack\n");
                if(mGoStraight1_ColorJudgeBlack->run()){//黒で止まる
                    blockState++;
                }
                    return false;
            }else if (blockState == 5){
                printf("TurnBack\n");
                if(mGoStraightBack_DistanceBack1->run()){//後退、距離後退1
                    blockState++;
                }
                    return false;
            }else if (blockState == 6){
                printf("LeftTrun\n");
                if(mTurnLeft_AngleLeft1->run()){//左旋回、指定角度左1
                    blockState++;
                }
                    return false;
            }else if (blockState == 7){
                printf("LTBlue\n");
                if(mLineTrace_ColorJudgeBlue->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 8){
                printf("PassCircle\n");
                if(mGoStraight1_Distance7->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 9){
                printf("LTRed\n");
                if(mLineTrace_ColorJudgeRed->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 10){
                printf("TurnGo\n");
                if(mGoStraight2_Distance16->run()){//直進2、指定距離1
                    blockState++;
                }
                    return false;
                
            }else if (blockState == 11){
                printf("RightTurn\n");
                if(mTurnRight_AngleRight2->run()){//右旋回、指定角度右2
                    blockState++;
                }
                    return false;
            }else if (blockState == 12){
                printf("LTRed\n");
                if(mLineTrace_ColorJudgeRed->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 13){
                printf("ArmUp\n");
                if(mArmUp_ArmJudgeUp->run()){
                    blockState=1;
                    return true;
                }
                    return false;
            }
        }else if (mScenarioNumber == 2){//パターン2シナリオ2の場合(一個目からゴールまで)
            if (blockState == 1){
                if(mArmDown_ArmJudgeDown->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 2){
                if(mTurnRight_AngleRight5->run()){//ちょっと右に
                    blockState++;
                }
                return false;
            }else if (blockState == 3){
                if(mGoStraight1_Distance8->run()){//直進1、指定距離8
                    blockState++;
                }
                return false;
            }else if (blockState == 4){
                if(mGoStraight3_Distance6->run()){//直進1、指定距離6
                    blockState++;
                }
                    return false;
            }else if (blockState == 5){
                if(mTurnLeft_AngleLeft8->run()){//左旋回、指定角度左8
                    blockState++;
                }
                    return false;
            }else if (blockState == 6){
                if(mGoStraight1_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 7){
                if(mGoStraight2_Distance1->run()){//直進1、指定距離8
                    blockState++;
                }
                return false;
            }else if (blockState == 8){
                if(mTurnLeft_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 9){
                if(mTurnRight_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 10){
                if(mLineTrace_ColorJudgeBlue->run()){
                    blockState=0;
                    return true;
                }
                    return false;
            }
            
        }else if (mScenarioNumber == 3){//パターン2シナリオ3の場合(一個目から二個目まで)
            if (blockState == 1){
                if(mArmDown_ArmJudgeDown->run()){
                    blockState++;
                }
                return false;
            }
            if (blockState == 2){
                if(mGoStraight1_Distance3->run()){//直進1、指定距離3
                    blockState++;
                    return false;
                }
                return false;
            }else if (blockState == 3){
                if(mGoStraightBack_DistanceBack10->run()){//後退、指定距離後ろ3
                    blockState++;
                }
                return false;
            }else if (blockState == 4){
                if(mTurnRight_AngleRight3->run()){//右旋回_トレース開始
                    blockState++;
                }
                return false;
            }else if (blockState == 5){
                if(mLineTrace_ColorJudgeBlue->run()){//青トレース
                    blockState++;
                }
                return false;
            }else if (blockState == 6){
                if(mGoStraight1_Distance7->run()){//格子直線
                    blockState++;
                }
                    return false;
            }else if (blockState == 7){
                if(mLineTrace_ColorJudgeBlue->run()){//青トレース
                    blockState++;
                }
                return false;
            }else if (blockState == 8){
                if(mGoStraight2_Distance1->run()){//直進2、指定距離1
                    blockState++;
                }
                    return false;
                
            }else if (blockState == 9){
                if(mTurnRight_AngleRight2->run()){//右旋回、指定角度右2
                    blockState++;
                }
                    return false;
            }else if (blockState == 10){
                if(mLineTrace_ColorJudgeBlue->run()){//青トレース
                    blockState++;
                }
                return false;
            }else if (blockState == 11){
                if(mArmUp_ArmJudgeUp->run()){
                    blockState=1;
                    return true;
                }
                    return false;
            } 
        }else if (mScenarioNumber == 4){//パターン2シナリオ4の場合(二個目からゴールまで)
            if (blockState == 1){
                if(mArmDown_ArmJudgeDown->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 2){
                if(mGoStraight1_Distance8->run()){//直進1、指定距離8
                    blockState++;
                }
                return false;
            }else if (blockState == 3){//右11
                if(mTurnRight_AngleRight11->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 4){  
                if(mGoStraight3_Distance9->run()){//直進1、指定距離9
                    blockState++;
                }
                    return false;
            }else if (blockState == 5){
                if(mGoStraight1_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 6){
                if(mGoStraight2_Distance1->run()){//直進1、指定距離8
                    blockState++;
                }
                return false;
            }else if (blockState == 7){
                 if(mTurnLeft_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 8){
                if(mTurnRight_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 9){
                if(mLineTrace_ColorJudgeBlue->run()){
                    blockState=1;
                    return true;
                }
                    return false;
            }
            
        }else if (mScenarioNumber == 5){//パターン2シナリオ5の場合(三個目からゴールまで)
            if (blockState == 1){
                if(mArmDown_ArmJudgeDown->run()){
                    blockState++;
                }
                return false;
            }
            if (blockState == 2){ 
                if(mGoStraight1_Distance3->run()){//直進1、指定距離3
                    blockState++;
                    return false;
                }
                return false;
            }else if (blockState == 3){
                if(mGoStraightBack_DistanceBack5->run()){//後退、指定距離後5
                    blockState++;
                }
                return false;
            }else if (blockState == 4){
                if(mTurnRight_AngleRight3->run()){//右旋回、
                    blockState++;
                }
                return false;
            }else if (blockState == 5){
                if(mLineTrace_ColorJudgeBlue->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 6){
                if(mGoStraight2_Distance1->run()){//直進2、指定距離1
                    blockState++;
                }
                    return false; 
            }else if (blockState == 7){
                if(mTurnRight_AngleRight2->run()){//右旋回、指定角度右2
                    blockState++;
                }
                    return false;
            }else if (blockState == 8){
                if(mLineTrace_ColorJudgeBlue->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 9){
                if(mGoStraight1_Distance7->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 10){
                if(mLineTrace_ColorJudgeGreen->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 11){
                if(mGoStraight2_Distance18->run()){//直進2、指定距離1
                    blockState++;
                }
                    return false; 
            }else if (blockState == 12){
                if(mTurnRight_AngleRight2->run()){//右旋回、指定角度右2
                    blockState++;
                }
                    return false;
            }else if (blockState == 13){
                if(mLineTrace_ColorJudgeGreen->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 14){
                if(mGoStraightBack_DistanceBack8->run()){//後退、距離後退2  
                    blockState++;
                }
                    return false;
            }else if (blockState == 15){
                if(mTurnLeft_AngleLeft2->run()){//左旋回、指定角度左2
                    blockState++;
                }
                    return false;
            }else if (blockState == 16){
                if(mLineTrace_ColorJudgeGreen->run()){
                    blockState+=1;
                }
                    return false;
            }else if (blockState == 17){
                if(mGoStraight1_Distance8->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 18){
                if(mTurnLeft_AngleLeft10->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 19){
                if(mGoStraight1_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 20){
                if(mGoStraight2_Distance1->run()){//直進1、指定距離8
                    blockState++;
                }
                return false;
            }else if (blockState == 21){
                if(mTurnLeft_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 22){
                if(mTurnRight_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 23){
                if(mLineTrace_ColorJudgeBlue->run()){
                    blockState=1;
                    return true;
                }
                    return false;
            }
            
        }

    }else if (mPatern == 3){//-------------------パターン3--------------------------
        if (mScenarioNumber == 1){//パターン3シナリオ1の場合
            if (blockState == 1){
                if(mArmDown_ArmJudgeDown->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 2){
                if(mLineTrace_ColorJudgeRed->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 3){
                if(mTurnRight_AngleRight1->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 4){
                if(mGoStraight1_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 5){
                if(mGoStraightBack_DistanceBack1->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 6){
                if(mTurnLeft_AngleLeft1->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 7){
                if(mLineTrace_ColorJudgeBlue->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 8){
                if(mGoStraight1_Distance7->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 9){
                if(mLineTrace_ColorJudgeRed->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 10){
                if(mGoStraight1_Distance7->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 11){
                if(mLineTrace_ColorJudgeRed->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 12){
                if(mArmUp_ArmJudgeUp->run()){
                    blockState=1;
                    return true;
                }
                    return false;
            }
        }else if (mScenarioNumber == 2){//パターン3シナリオ2の場合(一個目からゴールまで)
            if (blockState == 1){
                if(mArmDown_ArmJudgeDown->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 2){
                if(mGoStraight1_Distance8->run()){
                     
                    blockState++;
                }
                return false;
            }else if (blockState == 3){
                if(mTurnRight_AngleRight7->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 4){
                if(mGoStraight3_Distance10->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 5){
                if(mTurnLeft_AngleLeft11->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 6){
                if(mGoStraight1_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 7){
                if(mGoStraight2_Distance1->run()){//直進1、指定距離8
                    blockState++;
                }
                return false;
            }else if (blockState == 8){
                if(mTurnLeft_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 9){
                if(mTurnRight_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 10){
                if(mLineTrace_ColorJudgeBlue->run()){
                    blockState=1;
                    return true;
                }
                    return false;
            }
        }else if (mScenarioNumber == 3){//パターン3シナリオ3の場合(一個目から二個目まで)
            if (blockState == 1){
                if(mArmDown_ArmJudgeDown->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 2){
                if(mGoStraight1_Distance3->run()){
                    blockState++;
                    return false;
                }
                return false;
            }else if (blockState == 3){
                if(mGoStraightBack_DistanceBack10->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 4){
                if(mTurnRight_AngleRight3->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 5){
                if(mLineTrace_ColorJudgeRed->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 6){
                if(mGoStraight2_Distance16->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 7){
                if(mTurnRight_AngleRight2->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 8){
                if(mLineTrace_ColorJudgeRed->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 9){
                if(mGoStraight1_Distance7->run()){  
                    blockState++;
                }
                return false;
            }else if (blockState == 10){
                if(mLineTrace_ColorJudgeBlue->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 11){
                if(mArmUp_ArmJudgeUp->run()){
                    blockState=1;
                    return true;
                }
                    return false;
            } 
        }else if (mScenarioNumber == 4){//パターン3シナリオ4の場合(二個目からゴールまで)
            if (blockState == 1){
                if(mArmDown_ArmJudgeDown->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 2){
                if(mGoStraight1_Distance8->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 3){
                if(mTurnLeft_AngleLeft12->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 4){
                if(mGoStraight3_Distance11->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 5){
                if(mGoStraight1_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 6){
                if(mGoStraight2_Distance1->run()){//直進1、指定距離8
                    blockState++;
                }
                return false;
            }else if (blockState == 7){
                if(mTurnLeft_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 8){
                if(mTurnRight_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 9){
                if(mLineTrace_ColorJudgeBlue->run()){
                    blockState=1;
                    return true;
                }
                    return false;
            }
            
        }else if (mScenarioNumber == 5){//パターン3シナリオ5の場合(三個目からゴールまで)
            if (blockState == 1){
                if(mArmDown_ArmJudgeDown->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 2){
                if(mGoStraight1_Distance3->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 3){
                if(mGoStraightBack_DistanceBack13->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 4){
                if(mTurnLeft_AngleLeft4->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 5){
                if(mLineTrace_ColorJudgeGreen->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 6){
                if(mGoStraightBack_DistanceBack7->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 7){
                if(mTurnLeft_AngleLeft2->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 8){
                if(mLineTrace_ColorJudgeYellow->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 9){
                if(mTurnRight_AngleRight8->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 10){
                if(mGoStraight1_Distance12->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 11){
                if(mTurnLeft_AngleLeft13->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 12){
                if(mGoStraight1_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 13){
                if(mGoStraight2_Distance1->run()){//直進1、指定距離8
                    blockState++;
                }
                return false;
            }else if (blockState == 14){
                if(mTurnLeft_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 15){
                if(mTurnRight_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 16){
                if(mLineTrace_ColorJudgeBlue->run()){
                    blockState=1;
                    return true;
                }
                    return false;
            }
            
            
        }
    }else if (mPatern == 4){//---------------------パターン4------------------
        if (mScenarioNumber == 1){//パターン4シナリオ1の場合
            if (blockState == 1){
                if(mArmDown_ArmJudgeDown->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 2){
                if(mLineTrace_ColorJudgeRed->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 3){
                if(mTurnRight_AngleRight1->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 4){
                if(mGoStraight1_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 5){
                if(mGoStraightBack_DistanceBack1->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 6){
                if(mTurnLeft_AngleLeft1->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 7){
                if(mLineTrace_ColorJudgeBlue->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 8){
                if(mGoStraight2_Distance1->run()){
                    blockState++;
                }
                    return false;
                
            }else if (blockState == 9){
                if(mTurnRight_AngleRight2->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 10){
                if(mLineTrace_ColorJudgeBlue->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 11){
                if(mArmUp_ArmJudgeUp->run()){
                    blockState=1;
                    return true;
                }
                    return false;
            }
        }else if (mScenarioNumber == 2){//パターン4シナリオ2の場合(一個目からゴールまで)
            if (blockState == 1){
                if(mArmDown_ArmJudgeDown->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 2){
                if(mGoStraight3_Distance2->run()){//直進1、指定距離2
                    blockState++;
                }
                return false;
            }else if (blockState == 3){
                if(mTurnLeft_AngleLeft3->run()){//左旋回、指定角度左3
                    blockState++;
                }
                    return false;
            }else if (blockState == 4){
                if(mGoStraight1_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 5){
                if(mGoStraight2_Distance1->run()){//直進1、指定距離8
                    blockState++;
                }
                return false;
            }else if (blockState == 6){
                if(mTurnLeft_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 7){
                if(mTurnRight_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 8){
                if(mLineTrace_ColorJudgeBlue->run()){
                    blockState=1;
                    return true;
                }
                    return false;
            }
        }else if (mScenarioNumber == 3){//パターン4シナリオ3の場合(一個目から二個目まで)
            if (blockState == 1){
                if(mArmDown_ArmJudgeDown->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 2){
                if(mGoStraight1_Distance3->run()){
                    blockState++;
                    return false;
                }
                return false;
            }else if (blockState == 3){
                if(mGoStraightBack_DistanceBack3->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 4){
                if(mTurnLeft_AngleLeft4->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 5){
                if(mLineTrace_ColorJudgeRed->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 6){
                if(mGoStraight1_Distance7->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 7){
                if(mLineTrace_ColorJudgeRed->run()){
                    blockState+=1;
                }
                return false;
            }else if (blockState == 8){
                if(mGoStraight2_Distance16->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 9){
                if(mTurnRight_AngleRight2->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 10){
                if(mLineTrace_ColorJudgeYellow->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 11){
                if(mArmUp_ArmJudgeUp->run()){
                    blockState=1;
                    return true;
                }
                return false;
            }
        }else if (mScenarioNumber == 4){//パターン4シナリオ4の場合(二個目からゴールまで)
            if (blockState == 1){
                if(mArmDown_ArmJudgeDown->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 2){
                if(mGoStraight1_Distance8->run()){//直進1、指定距離8
                    blockState++;
                }
                return false;
            }else if (blockState == 3){
                if(mTurnRight_AngleRight9->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 4){
                if(mGoStraight1_Distance13->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 5){
                if(mTurnLeft_AngleLeft14->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 6){
                if(mGoStraight1_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 7){
                if(mGoStraight2_Distance1->run()){//直進1、指定距離8
                    blockState++;
                }
                return false;
            }else if (blockState == 8){
                if(mTurnLeft_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 9){
                if(mTurnRight_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 10){
                if(mLineTrace_ColorJudgeBlue->run()){
                    blockState=1;
                    return true;
                }
                    return false;
            }
            
        }else if (mScenarioNumber == 5){//パターン4シナリオ5の場合(三個目からゴールまで)
            if (blockState == 1){
                if(mArmDown_ArmJudgeDown->run()){
                    blockState++;
                }
                return false;
            }
            if (blockState == 2){
                if(mGoStraight1_Distance3->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 3){
                if(mGoStraightBack_DistanceBack12->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 4){
                if(mTurnRight_AngleRight3->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 5){
                if(mLineTrace_ColorJudgeYellow->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 6){
                if(mGoStraight1_Distance7->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 7){
                if(mLineTrace_ColorJudgeGreen->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 8){
                if(mGoStraight1_Distance7->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 9){
                if(mLineTrace_ColorJudgeGreen->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 10){
                if(mGoStraightBack_DistanceBack8->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 11){
                if(mTurnLeft_AngleLeft2->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 12){
                if(mLineTrace_ColorJudgeGreen->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 13){
                if(mTurnLeft_AngleLeft15->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 14){
                if(mGoStraight1_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 15){
                if(mGoStraight2_Distance1->run()){//直進1、指定距離8
                    blockState++;
                }
                return false;
            }else if (blockState == 16){
                if(mTurnLeft_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 17){
                if(mTurnRight_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 18){
                if(mLineTrace_ColorJudgeBlue->run()){
                    blockState=1;
                    return true;
                }
                    return false;
            }
            
        }
        
    }else if (mPatern == 5){//--------------------パターン5----------------
        if (mScenarioNumber == 1){//パターン5シナリオ1の場合
            if (blockState == 1){
                if(mArmDown_ArmJudgeDown->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 2){
                if(mLineTrace_ColorJudgeRed->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 3){
                if(mTurnRight_AngleRight1->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 4){
                if(mGoStraight1_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 5){
                if(mGoStraightBack_DistanceBack1->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 6){
                if(mTurnLeft_AngleLeft1->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 7){
                if(mLineTrace_ColorJudgeBlue->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 8){
                if(mGoStraight1_Distance7->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 9){
                if(mLineTrace_ColorJudgeRed->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 10){
                if(mGoStraight1_Distance7->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 11){
                if(mLineTrace_ColorJudgeRed->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 12){
                if(mArmUp_ArmJudgeUp->run()){
                    blockState=1;
                    return true;
                }
                    return false;
            }
        }else if (mScenarioNumber == 2){//パターン5シナリオ2の場合(一個目からゴールまで)
            if (blockState == 1){
                if(mArmDown_ArmJudgeDown->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 2){
                if(mGoStraight1_Distance8->run()){
                     
                    blockState++;
                }
                return false;
            }else if (blockState == 3){
                if(mTurnRight_AngleRight7->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 4){
                if(mGoStraight3_Distance10->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 5){
                if(mTurnLeft_AngleLeft11->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 6){
                if(mGoStraight1_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 7){
                if(mGoStraight2_Distance1->run()){//直進1、指定距離8
                    blockState++;
                }
                return false;
            }else if (blockState == 8){
                if(mTurnLeft_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 9){
                if(mTurnRight_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 10){
                if(mLineTrace_ColorJudgeBlue->run()){
                    blockState=1;
                    return true;
                }
                    return false;
            }
        }else if (mScenarioNumber == 3){//パターン5シナリオ3の場合(一個目から二個目まで)
            if (blockState == 1){
                if(mArmDown_ArmJudgeDown->run()){
                    blockState++;
                }
                return false;
            }
            if (blockState == 2){
                if(mGoStraight1_Distance3->run()){
                    blockState++;
                    return false;
                }
                return false;
            }else if (blockState == 3){
                if(mGoStraightBack_DistanceBack10->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 4){
                if(mTurnRight_AngleRight3->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 5){
                if(mLineTrace_ColorJudgeRed->run()){
                    blockState+=2;
                }
                return false;
            }else if (blockState == 6){
                if(mGoStraight2_Distance16->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 7){
                if(mTurnRight_AngleRight2->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 8){
                if(mLineTrace_ColorJudgeRed->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 9){
                if(mGoStraight1_Distance7->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 10){
                if(mLineTrace_ColorJudgeBlue->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 11){
                if(mGoStraight1_Distance7->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 12){
                if(mLineTrace_ColorJudgeBlue->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 13){
                if(mArmUp_ArmJudgeUp->run()){
                    blockState=1;
                    return true;
                }
                    return false;
            } 
        }else if (mScenarioNumber == 4){//パターン5シナリオ4の場合(二個目からゴールまで)
            if (blockState == 1){
                if(mArmDown_ArmJudgeDown->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 2){
                if(mGoStraight1_Distance8->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 3){
                if(mTurnLeft_AngleLeft16->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 4){
                if(mGoStraight3_Distance14->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 5){
                if(mGoStraight1_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 6){
                if(mGoStraight2_Distance1->run()){//直進1、指定距離8
                    blockState++;
                }
                return false;
            }else if (blockState == 7){
                if(mTurnLeft_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 8){
                if(mTurnRight_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 9){
                if(mLineTrace_ColorJudgeBlue->run()){
                    blockState=1;
                    return true;
                }
                    return false;
            }
            
        }else if (mScenarioNumber == 5){//パターン5シナリオ5の場合(三個目からゴールまで)
            if (blockState == 1){
                if(mArmDown_ArmJudgeDown->run()){
                    blockState++;
                }
                return false;
            }
            if (blockState == 2){
                if(mGoStraight1_Distance3->run()){
                    blockState++;
                    return false;
                }
                return false;
            }else if (blockState == 3){
                if(mGoStraightBack_DistanceBack3->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 4){
                if(mTurnLeft_AngleLeft4->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 5){
                if(mLineTrace_ColorJudgeGreen->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 6){
                if(mGoStraightBack_DistanceBack7->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 7){
                if(mTurnLeft_AngleLeft2->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 8){
                if(mLineTrace_ColorJudgeGreen->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 9){
                if(mTurnRight_AngleRight10->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 10){
                if(mGoStraight3_Distance15->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 11){
                if(mGoStraight1_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 12){
                if(mGoStraight2_Distance1->run()){//直進1、指定距離8
                    blockState++;
                }
                return false;
            }else if (blockState == 13){
                if(mTurnLeft_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 14){
                if(mTurnRight_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 15){
                if(mLineTrace_ColorJudgeBlue->run()){
                    blockState=1;
                    return true;
                }
                    return false;
            }
            
        }
    }else if (mPatern == 6){//----------------Test--------------------
        if (blockState == 1){
                if(mArmDown_ArmJudgeDown->run()){
                    blockState++;
                }
                return false;
            }else if (blockState == 2){
                if(mLineTrace_ColorJudgeYellow->run()){
                    blockState+=1;
                }
                return false;
            }else if (blockState == 3){
                printf("TurnGo\n");
                if(mGoStraightBack_DistanceBack6->run()){//直進2、指定距離1
                    blockState++;
                }
                    return false;
                
            }else if (blockState == 4){
                if(mTurnLeft_AngleLeft2->run()){
                    blockState-=2;
                }
                return false;
            }else if (blockState == 4){
                if(mGoStraight1_ColorJudgeBlack->run()){
                    blockState++;
                }
                    return false;
            }else if (blockState == 5){
                if(mGoStraightBack_DistanceBack1->run()){
                    blockState == 2;
                }
                    return false;
            }
    }
    
}


