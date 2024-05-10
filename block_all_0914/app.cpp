/******************************************************************************
 *  app.cpp (for LEGO Mindstorms EV3)
 *  Created on: 2015/01/25
 *  Implementation of the Task main_task
 *  Author: Kazuhiro.Kawachi
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#include "app.h"
#include "RandomWalker.h"

// デストラクタ問題の回避
// https://github.com/ETrobocon/etroboEV3/wiki/problem_and_coping
//void *__dso_handle=0;

// using宣言
using ev3api::TouchSensor;
using ev3api::Motor;
using ev3api::ColorSensor;

// Device objects
// オブジェクトを静的に確保する
TouchSensor gTouchSensor(PORT_1);

ColorSensor gColorSensor(PORT_2);
Motor       gLeftWheel(PORT_C);
Motor       gRightWheel(PORT_B);
Motor       gLeftWheelJudge(PORT_C);
Motor       gRightWheelJudge(PORT_B);
Motor       gArm(PORT_A);


// オブジェクトの定義

static int            patern;

static Walker          *gWalker;
static LineMonitor     *gLineMonitor;
static Starter         *gStarter;
static LineTracer      *gLineTracer;


//motion
static GoStraight      *gGoStraight1;//前進
static GoStraight      *gGoStraight2;//格子内、微直進
static GoStraight      *gGoStraight3;//高速移動

static GoStraight      *gGoStraightBack;//後退

static Turn            *gTurnLeft;//左折
static Turn            *gTurnRight;//右折

static Arm             *gArmUp;//アームを上げる
static Arm             *gArmDown;//アームを下げる

static LineTrace      *gLineTrace;//ライントレース

//judge
//ゴールラインは、ラインとレースしてゴールする黒ラインのこと
static Angle           *gAngleRight1;//ブロックハントエリア侵入(上へ)の角度調整用
static Angle           *gAngleRight2;//格子、右折用
static Angle           *gAngleRight3;//ブロック移動後のライン復帰
static Angle           *gAngleRight4;//パターン1、3個目保持しながらブロック脱出への角度調整
static Angle           *gAngleRight5;//パターン2、2個目保持しながらブロック脱出への角度調整
static Angle           *gAngleRight6;//ブロック侵入（下へ）への調整用
static Angle           *gAngleRight7;//パターン3、一個目を持ってブロック脱出への角度調節　and　パターン5、一個目
static Angle           *gAngleRight8;//パターン3、三個目を持ってブロック脱出への角度調節
static Angle           *gAngleRight9;//パターン4、二個目を持って、ブロック脱出への角度調節
static Angle           *gAngleRight10;//パターン5、三個目を持って、ブロック脱出への角度調節
static Angle           *gAngleRight11;//ブロックハントエリア侵入(下へ)の角度調整用

static Angle           *gAngleLeft1;//ブロック侵入（上へ）の調整用
static Angle           *gAngleLeft2;//格子、左折用
static Angle           *gAngleLeft3;//パターン1、一個目保持しながらゴールラインへ角度調整　and　パターン4、一個目からゴールラインへ角度調節
static Angle           *gAngleLeft4;//ブロック移動後のライン復帰
static Angle           *gAngleLeft5;//パターン1、二個目持った後ブロック脱出へ角度調整回転
static Angle           *gAngleLeft6;//パターン1、二個目を保持しながらゴールラインへ角度調整
static Angle           *gAngleLeft7;//パターン1、三個目保持しながら、ゴールラインへ角度調整
static Angle           *gAngleLeft8;//パターン2、2個目を保持しながら、ゴールラインへ角度調節
static Angle           *gAngleLeft9;//パターン2、１個目保持しながら、ブロック脱出へ角度調節
static Angle           *gAngleLeft10;//パターン2、3個目保持しながら、ブロック脱出へ角度調節
static Angle           *gAngleLeft11;//パターン3、一個目保持しながら、ブロック脱出へ角度調節
static Angle           *gAngleLeft12;//パターン3、二個目を保持しながら、ブロック脱出、そのままゴールラインへの角度調整
static Angle           *gAngleLeft13;//パターン3、三個目を保持しながら、ゴールラインへの角度調整
static Angle           *gAngleLeft14;//パターン4、二個目を保持しながら、ゴールラインへの角度調整
static Angle           *gAngleLeft15;//パターン4、三個目を保持しながら、ゴールラインへの角度調節
static Angle           *gAngleLeft16;//パターン5、二個目を保持しながら、ブロック脱出、そのままゴールラインへの角度調節

static Distance        *gDistance1;//格子、青、右折前用
static Distance        *gDistance2;//パターン1、一個目を持ってブロック脱出  and　パターン4、一個目を持ってブロック脱出
static Distance        *gDistance3;//ブロック移動用
static Distance        *gDistance4;//パターン1、二個目を持ってブロック脱出
static Distance        *gDistance5;//パターン1、三つ目を持ってブロック脱出
static Distance        *gDistance6;//パターン2、2個目を持ってブロック脱出
static Distance        *gDistance7;//格子、直進用
static Distance        *gDistance8;//ブロックの色判定からブロックをホールドする
static Distance        *gDistance9;//パターン2、1個目を持ってブロック脱出
static Distance        *gDistance10;//パターン3、一個目を持ってブロック脱出
static Distance        *gDistance11;//パターン3、二個目を持ってブロック脱出
static Distance        *gDistance12;//パターン3、三個目を持ってブロック脱出
static Distance        *gDistance13;//パターン4、二個目を持ってブロック脱出
static Distance        *gDistance14;//パターン5、二個目を持ってブロック脱出
static Distance        *gDistance15;//パターン5、三個目を持ってブロック脱出
static Distance        *gDistance16;//格子、赤、右折前用
static Distance        *gDistance17;//格子、黄、右折前用
static Distance        *gDistance18;//格子、緑、右折前用

static Distance        *gDistanceBack1;//上へブロック侵入ライントレース調整用
static Distance        *gDistanceBack2;//格子内、青、左折用
static Distance        *gDistanceBack3;//ブロック移動から左折の、後退用、青
static Distance        *gDistanceBack4;//下へブロック侵入ライントレース調整用
static Distance        *gDistanceBack5;//ブロック移動から右折の後退用、青
static Distance        *gDistanceBack6;//格子内、赤、左折用
static Distance        *gDistanceBack7;//格子内、黄、左折用
static Distance        *gDistanceBack8;//格子内、緑、左折用
static Distance        *gDistanceBack9;//ブロック移動から左折の、後退用、赤
static Distance        *gDistanceBack10;//ブロック移動から右折の後退用、赤
static Distance        *gDistanceBack11;//ブロック移動から左折の、後退用、黄
static Distance        *gDistanceBack12;//ブロック移動から右折の後退用、黄
static Distance        *gDistanceBack13;//ブロック移動から左折の、後退用、緑
static Distance        *gDistanceBack14;//ブロック移動から右折の後退用、緑

static ArmJudge        *gArmJudgeUp;//アーム上げ用
static ArmJudge        *gArmJudgeDown;//アーム下げ用

static ColorJudge      *gColorJudgeRed;//赤色検知用
static ColorJudge      *gColorJudgeBlack;//黒色検知用
static ColorJudge      *gColorJudgeBlue;//青色検知用
static ColorJudge      *gColorJudgeGreen;//緑検知
static ColorJudge      *gColorJudgeYellow;//黄検知

static BlockJudge      *gBlockJudge;//輝度値取得用


//scene
static Scene           *gArmDown_ArmJudgeDown;//アームを下げる、アームを下げた判定
static Scene           *gLineTrace_ColorJudgeRed;//ライントレース、赤色検知
static Scene           *gTurnRight_AngleRight1;//右旋回、右角度判定1(ブロック侵入用)
static Scene           *gGoStraight1_ColorJudgeBlack;//直進、黒色検知
static Scene           *gGoStraightBack_DistanceBack1;//後退、後退距離1
static Scene           *gTurnLeft_AngleLeft1;//左旋回、左角度判定1(ブロック侵入調整用)
static Scene           *gLineTrace_ColorJudgeBlue;//ライントレース、青色判定
static Scene           *gGoStraight2_Distance1;//前進、指定距離1(格子内右旋回調整用)
static Scene           *gTurnRight_AngleRight2;//右旋回、右角度判定2(格子内右旋回用)
static Scene           *gArmUp_ArmJudgeUp;//アームを上げる、アームを上げた判定
static Scene           *gTurnLeft_AngleLeft2;//左旋回、左旋回角度2(格子内左旋回用)
static Scene           *gTurnRight_AngleRight3;//右旋回、右旋回角度3
static Scene           *gGoStraightBack_DistanceBack2;
static Scene           *gGostraight3_Distance2;
static Scene           *gTurnLeft_AngleLeft3;
static Scene           *gGoStraight1_Distance3;
static Scene           *gGoStraightBack_DistanceBack3;
static Scene           *gLineTrace_ColorJudgeGreen;
static Scene           *gLineTrace_ColorJudgeYellow;
static Scene           *gTurnLeft_AngleLeft4;
static Scene           *gTurnLeft_AngleLeft5;
static Scene           *gGoStraight3_Distance4;
static Scene           *gTurnLeft_AngleLeft6;
static Scene           *gTurnRight_AngleRight4;
static Scene           *gGoStraight1_Distance5;
static Scene           *gTurnLeft_AngleLeft7;
static Scene           *gTurnRight_AngleRight5;
static Scene           *gGoStraight3_Distance6;
static Scene           *gTurnLeft_AngleLeft8;
static Scene           *gTurnLeft_ColorJudgeBlack;
static Scene           *gGoStraight1_Distance7;
static Scene           *gGoStraight1_Distance8;
static Scene           *gTurnLeft_AngleLeft9;
static Scene           *gGoStraight3_Distance9;
static Scene           *gTurnLeft_AngleLeft10;
static Scene           *gGoStraightBack_DistanceBack4;
static Scene           *gTurnRight_AngleRight6;
static Scene           *gGoStraightBack_DistanceBack5;
static Scene           *gTurnRight_AngleRight7;
static Scene           *gTurnRight_AngleRight8;
static Scene           *gTurnRight_AngleRight9;
static Scene           *gTurnRight_AngleRight10;
static Scene           *gTurnLeft_AngleLeft11;
static Scene           *gTurnLeft_AngleLeft12;
static Scene           *gTurnLeft_AngleLeft13;
static Scene           *gTurnLeft_AngleLeft14;
static Scene           *gTurnLeft_AngleLeft15;
static Scene           *gTurnLeft_AngleLeft16;
static Scene           *gGoStraight3_Distance10;
static Scene           *gGoStraight3_Distance11;
static Scene           *gGoStraight1_Distance12;
static Scene           *gGoStraight1_Distance13;
static Scene           *gGoStraight3_Distance14;
static Scene           *gGoStraight3_Distance15;
static Scene           *gTurnRight_AngleRight11;
static Scene           *gGoStraight2_Distance16;
static Scene           *gGoStraight2_Distance17;
static Scene           *gGoStraight2_Distance18;
static Scene           *gGoStraightBack_DistanceBack6;
static Scene           *gGoStraightBack_DistanceBack7;
static Scene           *gGoStraightBack_DistanceBack8;
static Scene           *gGoStraightBack_DistanceBack9;
static Scene           *gGoStraightBack_DistanceBack10;
static Scene           *gGoStraightBack_DistanceBack11;
static Scene           *gGoStraightBack_DistanceBack12;
static Scene           *gGoStraightBack_DistanceBack13;
static Scene           *gGoStraightBack_DistanceBack14;
static Scene           *gTurnRight_ColorJudgeBlack;



static Scenario        *gScenario1;
static Scenario        *gScenario2;
static Scenario        *gScenario3;
static Scenario        *gScenario4;
static Scenario        *gScenario5;

static ScenarioManager *gScenarioManager;
static RandomWalker    *gRandomWalker;




/**
 * EV3システム生成
 */
static void user_system_create() {
    // [TODO] タッチセンサの初期化に2msのdelayがあるため、ここで待つ
    tslp_tsk(2U * 1000U);

    // オブジェクトの作成
    //オブジェクトは部品の小さいものから作成

    patern         = 1;
    //unit
    gWalker          = new Walker(gLeftWheel,
                                    gRightWheel);
    gLineMonitor     = new LineMonitor(gColorSensor);
    gStarter         = new Starter(gTouchSensor);

    //motion
    gLineTrace      = new LineTrace(gLineMonitor, gWalker);
    gLineTracer     = new LineTracer(gLineMonitor, gWalker,gColorJudgeRed);
    gTurnLeft      = new Turn(gLeftWheel,
                                    gRightWheel,
                                    0);
    gTurnRight      = new Turn(gLeftWheel,
                                    gRightWheel,
                                    1);
    gArmUp           = new Arm(gArm,0);
    gArmDown           = new Arm(gArm,1);
    gGoStraight1      = new GoStraight(gLeftWheel,
                                        gRightWheel,45);//45
    gGoStraight2      = new GoStraight(gLeftWheel,
                                        gRightWheel,45);
    gGoStraight3      = new GoStraight(gLeftWheel,
                                        gRightWheel,70);

    gGoStraightBack      = new GoStraight(gLeftWheel,
                                        gRightWheel,-40);


    //judge
    //三つ目の引数が指定する角位置
    gAngleRight1         = new Angle(gLeftWheelJudge,
                                        gRightWheelJudge,165,1);//ブロックハントエリア侵入（上へ）の角度調整用
    gAngleRight2         = new Angle(gLeftWheelJudge,
                                        gRightWheelJudge,210,1);//格子、右折用
    gAngleRight3        = new Angle(gLeftWheelJudge,
                                        gRightWheelJudge,150,1);//ブロック移動後のライン復帰
    gAngleRight4        = new Angle(gLeftWheelJudge,
                                        gRightWheelJudge,120,1);//パターン1、3個目保持しながらブロック脱出への角度調整
    gAngleRight5        = new Angle(gLeftWheelJudge,
                                        gRightWheelJudge,30,1);//パターン2、2個目保持しながらブロック脱出への角度調整
    gAngleRight6 = new Angle(gLeftWheelJudge,
                                        gRightWheelJudge,220,1);//ブロック侵入（下へ）の調整用
    gAngleRight7 = new Angle(gLeftWheelJudge,
                                        gRightWheelJudge,300,1);//パターン3、一個目を持ってブロック脱出への角度調節　and　パターン5、一個目
    gAngleRight8 = new Angle(gLeftWheelJudge,
                                        gRightWheelJudge,240,1);//パターン3、三個目を持ってブロック脱出への角度調節
    gAngleRight9 = new Angle(gLeftWheelJudge,
                                        gRightWheelJudge,100,1);//パターン4、二個目を持って、ブロック脱出への角度調節
    gAngleRight10 = new Angle(gLeftWheelJudge,
                                        gRightWheelJudge,180,1);//パターン5、三個目を持って、ブロック脱出への角度調節
    gAngleRight11         = new Angle(gLeftWheelJudge,
                                        gRightWheelJudge,420,1);//ブロックハントエリア侵入(下へ)の角度調整用

    //三つ目の引数が指定する角位置
    gAngleLeft1         = new Angle(gLeftWheelJudge,
                                        gRightWheelJudge,157,0);//ブロック侵入(上へ)の調整用
    gAngleLeft2           = new Angle(gLeftWheelJudge,
                                        gRightWheelJudge,208,0);//格子内、左折用 208
    gAngleLeft3           = new Angle(gLeftWheelJudge,
                                        gRightWheelJudge,20,0);//パターン1、一個目保持しながらゴールラインへ角度調整　and　パターン4、一個目からゴールラインへ角度調節
    gAngleLeft4           = new Angle(gLeftWheelJudge,
                                        gRightWheelJudge,205,0);//ブロック移動後のライン復帰
    gAngleLeft5           = new Angle(gLeftWheelJudge,
                                        gRightWheelJudge,400,0);//パターン1、二個目持った後ブロック脱出へ角度調整回転
    gAngleLeft6           = new Angle(gLeftWheelJudge,
                                        gRightWheelJudge,100,0);//パターン1、二個目を保持しながらゴールラインへ角度調整
    gAngleLeft7           = new Angle(gLeftWheelJudge,
                                        gRightWheelJudge,220,0);//パターン1、三個目保持しながら、ゴールラインへ角度調整
    gAngleLeft8           = new Angle(gLeftWheelJudge,
                                        gRightWheelJudge,150,0);//パターン2、1個目を保持しながら、ゴールラインへ角度調節
    gAngleLeft9           = new Angle(gLeftWheelJudge,
                                        gRightWheelJudge,460,0);//パターン2、2個目保持しながら、ブロック脱出へ角度調節
    gAngleLeft10          = new Angle(gLeftWheelJudge,
                                        gRightWheelJudge,60,0);//パターン2、3個目保持しながら、ブロック脱出へ角度調節
    gAngleLeft11          = new Angle(gLeftWheelJudge,
                                        gRightWheelJudge,90,0);//パターン3、一個目保持しながら、ブロック脱出へ角度調節
    gAngleLeft12          = new Angle(gLeftWheelJudge,
                                        gRightWheelJudge,230,0);//パターン3、二個目を保持しながら、ブロック脱出、そのままゴールラインへの角度調整
    gAngleLeft13          = new Angle(gLeftWheelJudge,
                                        gRightWheelJudge,60,0);//パターン3、三個目を保持しながら、ゴールラインへの角度調整
    gAngleLeft14          = new Angle(gLeftWheelJudge,
                                        gRightWheelJudge,130,0);//パターン4、二個目を保持しながら、ゴールラインへの角度調整
    gAngleLeft15          = new Angle(gLeftWheelJudge,
                                        gRightWheelJudge,15,0);//パターン4、三個目を保持しながら、ゴールラインへの角度調節
    gAngleLeft16          = new Angle(gLeftWheelJudge,
                                        gRightWheelJudge,240,0);//パターン5、二個目を保持しながら、ブロック脱出、そのままゴールラインへの角度調節


    //三つ目の引数が指定する角位置
    gDistance1      = new Distance(gLeftWheelJudge,
                                        gRightWheelJudge,5,0);//格子、青、右折前用 5 testchenge
    gDistance2      = new Distance(gLeftWheelJudge,
                                        gRightWheelJudge,1000,0);//パターン1、一個目から直進
    gDistance3      = new Distance(gLeftWheelJudge,
                                        gRightWheelJudge,90,0);//ブロック移動、直進用
    gDistance4      = new Distance(gLeftWheelJudge,
                                        gRightWheelJudge,1400,0);//パターン1、二個目を持ってブロック脱出
    gDistance5      = new Distance(gLeftWheelJudge,
                                        gRightWheelJudge,500,0);//パターン1、三つ目を持ってブロック脱出
    gDistance6      = new Distance(gLeftWheelJudge,
                                        gRightWheelJudge,1150,0);//パターン2、二個目を持ってブロック脱出
    gDistance7      = new Distance(gLeftWheelJudge,
                                        gRightWheelJudge,80,0);//格子、直進用
    gDistance8      = new Distance(gLeftWheelJudge,
                                        gRightWheelJudge,50,0);//ブロックの色判定からブロックをホールドする
    gDistance9      = new Distance(gLeftWheelJudge,
                                        gRightWheelJudge,1400,0);//パターン2、一個目を持ってブロック脱出
    gDistance10      = new Distance(gLeftWheelJudge,
                                        gRightWheelJudge,1400,0);//パターン3、一個目を持ってブロック脱出
    gDistance11      = new Distance(gLeftWheelJudge,
                                        gRightWheelJudge,1000,0);//パターン3、二個目を持ってブロック脱出
    gDistance12      = new Distance(gLeftWheelJudge,
                                        gRightWheelJudge,700,0);//パターン3、三個目を持ってブロック脱出
    gDistance13      = new Distance(gLeftWheelJudge,
                                        gRightWheelJudge,600,0);//パターン4、二個目を持ってブロック脱出
    gDistance14      = new Distance(gLeftWheelJudge,
                                        gRightWheelJudge,1000,0);//パターン5、二個目を持ってブロック脱出
    gDistance15      = new Distance(gLeftWheelJudge,
                                        gRightWheelJudge,500,0);//パターン5、三個目を持ってブロック脱出
    gDistance16      = new Distance(gLeftWheelJudge,
                                        gRightWheelJudge,5,0);//格子、赤、右折前用
    gDistance17      = new Distance(gLeftWheelJudge,
                                        gRightWheelJudge,5,0);//格子、黄、右折前用
    gDistance18      = new Distance(gLeftWheelJudge,
                                        gRightWheelJudge,5,0);//格子、緑、右折前用

    //三つ目の引数が指定する角位置
    gDistanceBack1      = new Distance(gLeftWheelJudge,
                                        gRightWheelJudge,-34,1);//上へブロック侵入ライントレース調整用
    gDistanceBack2      = new Distance(gLeftWheelJudge,
                                        gRightWheelJudge,-0,1);//格子内、左折直前用
    gDistanceBack3      = new Distance(gLeftWheelJudge,
                                        gRightWheelJudge,-90,1);//ブロック移動から左折の、後退用
    gDistanceBack4      = new Distance(gLeftWheelJudge,
                                        gRightWheelJudge,-38,1);//下へブロック侵入ライントレース調整用
    gDistanceBack5      = new Distance(gLeftWheelJudge,
                                        gRightWheelJudge,-70,1);//ブロック移動から右折の後退用
    gDistanceBack6      = new Distance(gLeftWheelJudge,
                                        gRightWheelJudge,-5,1);//格子内、赤、左折用
    gDistanceBack7      = new Distance(gLeftWheelJudge,
                                        gRightWheelJudge,-5,1);//格子内、黄、左折用
    gDistanceBack8      = new Distance(gLeftWheelJudge,
                                        gRightWheelJudge,-5,1);//格子内、緑、左折用
    gDistanceBack9      = new Distance(gLeftWheelJudge,
                                        gRightWheelJudge,-105,1);//ブロック移動から左折の、後退用、赤
    gDistanceBack10      = new Distance(gLeftWheelJudge,
                                        gRightWheelJudge,-75,1);//ブロック移動から右折の後退用、赤
    gDistanceBack11      = new Distance(gLeftWheelJudge,
                                        gRightWheelJudge,-110,1);//ブロック移動から左折の、後退用、黄
    gDistanceBack12      = new Distance(gLeftWheelJudge,
                                        gRightWheelJudge,-80,1);//ブロック移動から右折の後退用、黄
    gDistanceBack13      = new Distance(gLeftWheelJudge,
                                        gRightWheelJudge,-110,1);//ブロック移動から左折の、後退用、緑
    gDistanceBack14      = new Distance(gLeftWheelJudge,
                                        gRightWheelJudge,-110,1);//ブロック移動から右折の後退用、緑
    

    gColorJudgeRed      = new ColorJudge(gColorSensor,COLOR_RED);
    gColorJudgeBlack      = new ColorJudge(gColorSensor,COLOR_BLACK);
    gColorJudgeBlue      = new ColorJudge(gColorSensor,COLOR_BLUE);
    gColorJudgeGreen      = new ColorJudge(gColorSensor,COLOR_GREEN);
    gColorJudgeYellow     = new ColorJudge(gColorSensor,COLOR_YELLOW);

    gBlockJudge           = new BlockJudge(gColorSensor,3);
    //0がアップジャッジ、1がダウンジャッジ
    gArmJudgeUp        = new ArmJudge(-50,gArm,0);
    gArmJudgeDown        = new ArmJudge(200,gArm,1);



    //scene
    gArmDown_ArmJudgeDown          = new Scene(gArmDown,gArmJudgeDown);
    gLineTrace_ColorJudgeRed       = new Scene(gLineTrace,gColorJudgeRed);
    gTurnRight_AngleRight1        = new Scene(gTurnRight,gAngleRight1);
    gGoStraight1_ColorJudgeBlack    = new Scene(gGoStraight1,gColorJudgeBlack);
    gGoStraightBack_DistanceBack1         = new Scene(gGoStraightBack,gDistanceBack1);
    gTurnLeft_AngleLeft1          = new Scene(gTurnLeft,gAngleLeft1);
    gLineTrace_ColorJudgeBlue      = new Scene(gLineTrace,gColorJudgeBlue);
    gGoStraight2_Distance1         = new Scene(gGoStraight2,gDistance1);
    gTurnRight_AngleRight2        = new Scene(gTurnRight,gAngleRight2);
    gArmUp_ArmJudgeUp              = new Scene(gArmUp,gArmJudgeUp);
    gTurnLeft_AngleLeft2           = new Scene(gTurnLeft,gAngleLeft2);
    gGoStraightBack_DistanceBack2 = new Scene(gGoStraightBack,gDistanceBack2);
    gGostraight3_Distance2         = new Scene(gGoStraight3,gDistance2);
    gTurnLeft_AngleLeft3          = new Scene(gTurnLeft,gAngleLeft3);
    gTurnRight_AngleRight3         = new Scene(gTurnRight,gAngleRight3);
    gGoStraight1_Distance3          = new Scene(gGoStraight1,gDistance3);
    gGoStraightBack_DistanceBack3   = new Scene(gGoStraightBack,gDistanceBack3);
    gLineTrace_ColorJudgeGreen      = new Scene(gLineTrace,gColorJudgeGreen);
    gLineTrace_ColorJudgeYellow     = new Scene(gLineTrace,gColorJudgeYellow);
    gTurnLeft_AngleLeft4            = new Scene(gTurnLeft,gAngleLeft4);
    gTurnLeft_AngleLeft5            = new Scene(gTurnLeft,gAngleLeft5);
    gGoStraight3_Distance4          = new Scene(gGoStraight3,gDistance4);
    gTurnLeft_AngleLeft6            = new Scene(gTurnLeft,gAngleLeft6);
    gTurnRight_AngleRight4          = new Scene(gTurnRight,gAngleRight4);
    gGoStraight1_Distance5          = new Scene(gGoStraight1,gDistance5);
    gTurnLeft_AngleLeft7            = new Scene(gTurnLeft,gAngleLeft7);
    gTurnRight_AngleRight5          = new Scene(gTurnRight,gAngleRight5);
    gGoStraight3_Distance6          = new Scene(gGoStraight3,gDistance6);
    gTurnLeft_AngleLeft8            = new Scene(gTurnLeft,gAngleLeft8);
    gTurnLeft_ColorJudgeBlack       = new Scene(gTurnLeft,gColorJudgeBlack);
    gGoStraight1_Distance7          = new Scene(gGoStraight1,gDistance7);
    gGoStraight1_Distance8          = new Scene(gGoStraight1,gDistance8);
    gTurnLeft_AngleLeft9            = new Scene(gTurnLeft,gAngleLeft9);
    gGoStraight3_Distance9          = new Scene(gGoStraight3,gDistance9);
    gTurnLeft_AngleLeft10           = new Scene(gTurnLeft,gAngleLeft10);
    gGoStraightBack_DistanceBack4   = new Scene(gGoStraightBack,gDistanceBack4);
    gTurnRight_AngleRight6          = new Scene(gTurnRight,gAngleRight6);
    gGoStraightBack_DistanceBack5   = new Scene(gGoStraightBack,gDistanceBack5);
    gTurnRight_AngleRight7          = new Scene(gTurnRight,gAngleRight7);
    gTurnRight_AngleRight8          = new Scene(gTurnRight,gAngleRight8);
    gTurnRight_AngleRight9          = new Scene(gTurnRight,gAngleRight9);
    gTurnRight_AngleRight10          = new Scene(gTurnRight,gAngleRight10);
    gTurnLeft_AngleLeft11           = new Scene(gTurnLeft,gAngleLeft11);
    gTurnLeft_AngleLeft12           = new Scene(gTurnLeft,gAngleLeft12);
    gTurnLeft_AngleLeft13           = new Scene(gTurnLeft,gAngleLeft13);
    gTurnLeft_AngleLeft14           = new Scene(gTurnLeft,gAngleLeft14);
    gTurnLeft_AngleLeft15           = new Scene(gTurnLeft,gAngleLeft15);
    gTurnLeft_AngleLeft16           = new Scene(gTurnLeft,gAngleLeft16);
    gGoStraight3_Distance10          = new Scene(gGoStraight3,gDistance10);
    gGoStraight3_Distance11          = new Scene(gGoStraight3,gDistance11);
    gGoStraight1_Distance12          = new Scene(gGoStraight1,gDistance12);
    gGoStraight1_Distance13          = new Scene(gGoStraight1,gDistance13);
    gGoStraight3_Distance14          = new Scene(gGoStraight3,gDistance14);
    gGoStraight3_Distance15          = new Scene(gGoStraight3,gDistance15);
    gTurnRight_AngleRight11          = new Scene(gTurnRight,gAngleRight11);
    gGoStraight2_Distance16         = new Scene(gGoStraight2,gDistance16);
    gGoStraight2_Distance17         = new Scene(gGoStraight2,gDistance17);
    gGoStraight2_Distance18         = new Scene(gGoStraight2,gDistance18);
    gGoStraightBack_DistanceBack6         = new Scene(gGoStraightBack,gDistanceBack6);
    gGoStraightBack_DistanceBack7         = new Scene(gGoStraightBack,gDistanceBack7);
    gGoStraightBack_DistanceBack8         = new Scene(gGoStraightBack,gDistanceBack8);
    gGoStraightBack_DistanceBack9         = new Scene(gGoStraightBack,gDistanceBack9);
    gGoStraightBack_DistanceBack10         = new Scene(gGoStraightBack,gDistanceBack10);
    gGoStraightBack_DistanceBack11        = new Scene(gGoStraightBack,gDistanceBack11);
    gGoStraightBack_DistanceBack12        = new Scene(gGoStraightBack,gDistanceBack12);
    gGoStraightBack_DistanceBack13        = new Scene(gGoStraightBack,gDistanceBack13);
    gGoStraightBack_DistanceBack14        = new Scene(gGoStraightBack,gDistanceBack14);
    gTurnRight_ColorJudgeBlack          = new Scene(gTurnRight,gColorJudgeBlack);


    //scenario
    gScenario1         = new Scenario(patern,1,gArmDown_ArmJudgeDown,
                                        gLineTrace_ColorJudgeRed,
                                        gTurnRight_AngleRight1,
                                        gGoStraight1_ColorJudgeBlack,
                                        gGoStraightBack_DistanceBack1,
                                        gTurnLeft_AngleLeft1,
                                        gLineTrace_ColorJudgeBlue,
                                        gGoStraight2_Distance1,
                                        gTurnRight_AngleRight2,
                                        gArmUp_ArmJudgeUp,
                                        gTurnLeft_AngleLeft2,
                                        gTurnRight_AngleRight3,
                                        gGoStraightBack_DistanceBack2,
                                        gGostraight3_Distance2,
                                        gTurnLeft_AngleLeft3,
                                        gGoStraight1_Distance3,
                                        gGoStraightBack_DistanceBack3,
                                        gLineTrace_ColorJudgeGreen,
                                        gLineTrace_ColorJudgeYellow,
                                        gTurnLeft_AngleLeft4,
                                        gTurnLeft_AngleLeft5,
                                        gGoStraight3_Distance4,
                                        gTurnLeft_AngleLeft6,
                                        gTurnRight_AngleRight4,
                                        gGoStraight1_Distance5,
                                        gTurnLeft_AngleLeft7,
                                        gTurnRight_AngleRight5,
                                        gGoStraight3_Distance6,
                                        gTurnLeft_AngleLeft8,
                                        gTurnLeft_ColorJudgeBlack,
                                        gGoStraight1_Distance7,
                                        gGoStraight1_Distance8,
                                        gTurnLeft_AngleLeft9,
                                        gGoStraight3_Distance9,
                                        gTurnLeft_AngleLeft10,
                                        gGoStraightBack_DistanceBack4,
                                        gTurnRight_AngleRight6,
                                        gGoStraightBack_DistanceBack5,
                                        gTurnRight_AngleRight7,
                                        gTurnRight_AngleRight8,
                                        gTurnRight_AngleRight9,
                                        gTurnRight_AngleRight10,
                                        gTurnLeft_AngleLeft11,
                                        gTurnLeft_AngleLeft12,
                                        gTurnLeft_AngleLeft13,
                                        gTurnLeft_AngleLeft14,
                                        gTurnLeft_AngleLeft15,
                                        gTurnLeft_AngleLeft16,
                                        gGoStraight3_Distance10,
                                        gGoStraight3_Distance11,
                                        gGoStraight1_Distance12,
                                        gGoStraight1_Distance13,
                                        gGoStraight3_Distance14,
                                        gGoStraight3_Distance15,
                                        gTurnRight_AngleRight11,
                                        gGoStraight2_Distance16,
                                        gGoStraight2_Distance17,
                                        gGoStraight2_Distance18,
                                        gGoStraightBack_DistanceBack6,
                                        gGoStraightBack_DistanceBack7,
                                        gGoStraightBack_DistanceBack8,
                                        gGoStraightBack_DistanceBack9,
                                        gGoStraightBack_DistanceBack10,
                                        gGoStraightBack_DistanceBack11,
                                        gGoStraightBack_DistanceBack12,
                                        gGoStraightBack_DistanceBack13,
                                        gGoStraightBack_DistanceBack14,
                                        gTurnRight_ColorJudgeBlack  );

    gScenario2         = new Scenario(patern,2,gArmDown_ArmJudgeDown,
                                        gLineTrace_ColorJudgeRed,
                                        gTurnRight_AngleRight1,
                                        gGoStraight1_ColorJudgeBlack,
                                        gGoStraightBack_DistanceBack1,
                                        gTurnLeft_AngleLeft1,
                                        gLineTrace_ColorJudgeBlue,
                                        gGoStraight2_Distance1,
                                        gTurnRight_AngleRight2,
                                        gArmUp_ArmJudgeUp,
                                        gTurnLeft_AngleLeft2,
                                        gTurnRight_AngleRight3,
                                        gGoStraightBack_DistanceBack2,
                                        gGostraight3_Distance2,
                                        gTurnLeft_AngleLeft3,
                                        gGoStraight1_Distance3,
                                        gGoStraightBack_DistanceBack3,
                                        gLineTrace_ColorJudgeGreen,
                                        gLineTrace_ColorJudgeYellow,
                                        gTurnLeft_AngleLeft4,
                                        gTurnLeft_AngleLeft5,
                                        gGoStraight3_Distance4,
                                        gTurnLeft_AngleLeft6,
                                        gTurnRight_AngleRight4,
                                        gGoStraight1_Distance5,
                                        gTurnLeft_AngleLeft7,
                                        gTurnRight_AngleRight5,
                                        gGoStraight3_Distance6,
                                        gTurnLeft_AngleLeft8,
                                        gTurnLeft_ColorJudgeBlack,
                                        gGoStraight1_Distance7,
                                        gGoStraight1_Distance8,
                                        gTurnLeft_AngleLeft9,
                                        gGoStraight3_Distance9,
                                        gTurnLeft_AngleLeft10,
                                        gGoStraightBack_DistanceBack4,
                                        gTurnRight_AngleRight6,
                                        gGoStraightBack_DistanceBack5,
                                        gTurnRight_AngleRight7,
                                        gTurnRight_AngleRight8,
                                        gTurnRight_AngleRight9,
                                        gTurnRight_AngleRight10,
                                        gTurnLeft_AngleLeft11,
                                        gTurnLeft_AngleLeft12,
                                        gTurnLeft_AngleLeft13,
                                        gTurnLeft_AngleLeft14,
                                        gTurnLeft_AngleLeft15,
                                        gTurnLeft_AngleLeft16,
                                        gGoStraight3_Distance10,
                                        gGoStraight3_Distance11,
                                        gGoStraight1_Distance12,
                                        gGoStraight1_Distance13,
                                        gGoStraight3_Distance14,
                                        gGoStraight3_Distance15,
                                        gTurnRight_AngleRight11,
                                        gGoStraight2_Distance16,
                                        gGoStraight2_Distance17,
                                        gGoStraight2_Distance18,
                                        gGoStraightBack_DistanceBack6,
                                        gGoStraightBack_DistanceBack7,
                                        gGoStraightBack_DistanceBack8,
                                        gGoStraightBack_DistanceBack9,
                                        gGoStraightBack_DistanceBack10,
                                        gGoStraightBack_DistanceBack11,
                                        gGoStraightBack_DistanceBack12,
                                        gGoStraightBack_DistanceBack13,
                                        gGoStraightBack_DistanceBack14,
                                        gTurnRight_ColorJudgeBlack  );

    gScenario3         = new Scenario(patern,3,gArmDown_ArmJudgeDown,
                                        gLineTrace_ColorJudgeRed,
                                        gTurnRight_AngleRight1,
                                        gGoStraight1_ColorJudgeBlack,
                                        gGoStraightBack_DistanceBack1,
                                        gTurnLeft_AngleLeft1,
                                        gLineTrace_ColorJudgeBlue,
                                        gGoStraight2_Distance1,
                                        gTurnRight_AngleRight2,
                                        gArmUp_ArmJudgeUp,
                                        gTurnLeft_AngleLeft2,
                                        gTurnRight_AngleRight3,
                                        gGoStraightBack_DistanceBack2,
                                        gGostraight3_Distance2,
                                        gTurnLeft_AngleLeft3,
                                        gGoStraight1_Distance3,
                                        gGoStraightBack_DistanceBack3,
                                        gLineTrace_ColorJudgeGreen,
                                        gLineTrace_ColorJudgeYellow,
                                        gTurnLeft_AngleLeft4,
                                        gTurnLeft_AngleLeft5,
                                        gGoStraight3_Distance4,
                                        gTurnLeft_AngleLeft6,
                                        gTurnRight_AngleRight4,
                                        gGoStraight1_Distance5,
                                        gTurnLeft_AngleLeft7,
                                        gTurnRight_AngleRight5,
                                        gGoStraight3_Distance6,
                                        gTurnLeft_AngleLeft8,
                                        gTurnLeft_ColorJudgeBlack,
                                        gGoStraight1_Distance7,
                                        gGoStraight1_Distance8,
                                        gTurnLeft_AngleLeft9,
                                        gGoStraight3_Distance9,
                                        gTurnLeft_AngleLeft10,
                                        gGoStraightBack_DistanceBack4,
                                        gTurnRight_AngleRight6,
                                        gGoStraightBack_DistanceBack5,
                                        gTurnRight_AngleRight7,
                                        gTurnRight_AngleRight8,
                                        gTurnRight_AngleRight9,
                                        gTurnRight_AngleRight10,
                                        gTurnLeft_AngleLeft11,
                                        gTurnLeft_AngleLeft12,
                                        gTurnLeft_AngleLeft13,
                                        gTurnLeft_AngleLeft14,
                                        gTurnLeft_AngleLeft15,
                                        gTurnLeft_AngleLeft16,
                                        gGoStraight3_Distance10,
                                        gGoStraight3_Distance11,
                                        gGoStraight1_Distance12,
                                        gGoStraight1_Distance13,
                                        gGoStraight3_Distance14,
                                        gGoStraight3_Distance15,
                                        gTurnRight_AngleRight11,
                                        gGoStraight2_Distance16,
                                        gGoStraight2_Distance17,
                                        gGoStraight2_Distance18,
                                        gGoStraightBack_DistanceBack6,
                                        gGoStraightBack_DistanceBack7,
                                        gGoStraightBack_DistanceBack8,
                                        gGoStraightBack_DistanceBack9,
                                        gGoStraightBack_DistanceBack10,
                                        gGoStraightBack_DistanceBack11,
                                        gGoStraightBack_DistanceBack12,
                                        gGoStraightBack_DistanceBack13,
                                        gGoStraightBack_DistanceBack14,
                                        gTurnRight_ColorJudgeBlack  );

    gScenario4         = new Scenario(patern,4,gArmDown_ArmJudgeDown,
                                        gLineTrace_ColorJudgeRed,
                                        gTurnRight_AngleRight1,
                                        gGoStraight1_ColorJudgeBlack,
                                        gGoStraightBack_DistanceBack1,
                                        gTurnLeft_AngleLeft1,
                                        gLineTrace_ColorJudgeBlue,
                                        gGoStraight2_Distance1,
                                        gTurnRight_AngleRight2,
                                        gArmUp_ArmJudgeUp,
                                        gTurnLeft_AngleLeft2,
                                        gTurnRight_AngleRight3,
                                        gGoStraightBack_DistanceBack2,
                                        gGostraight3_Distance2,
                                        gTurnLeft_AngleLeft3,
                                        gGoStraight1_Distance3,
                                        gGoStraightBack_DistanceBack3,
                                        gLineTrace_ColorJudgeGreen,
                                        gLineTrace_ColorJudgeYellow,
                                        gTurnLeft_AngleLeft4,
                                        gTurnLeft_AngleLeft5,
                                        gGoStraight3_Distance4,
                                        gTurnLeft_AngleLeft6,
                                        gTurnRight_AngleRight4,
                                        gGoStraight1_Distance5,
                                        gTurnLeft_AngleLeft7,
                                        gTurnRight_AngleRight5,
                                        gGoStraight3_Distance6,
                                        gTurnLeft_AngleLeft8,
                                        gTurnLeft_ColorJudgeBlack,
                                        gGoStraight1_Distance7,
                                        gGoStraight1_Distance8,
                                        gTurnLeft_AngleLeft9,
                                        gGoStraight3_Distance9,
                                        gTurnLeft_AngleLeft10,
                                        gGoStraightBack_DistanceBack4,
                                        gTurnRight_AngleRight6,
                                        gGoStraightBack_DistanceBack5,
                                        gTurnRight_AngleRight7,
                                        gTurnRight_AngleRight8,
                                        gTurnRight_AngleRight9,
                                        gTurnRight_AngleRight10,
                                        gTurnLeft_AngleLeft11,
                                        gTurnLeft_AngleLeft12,
                                        gTurnLeft_AngleLeft13,
                                        gTurnLeft_AngleLeft14,
                                        gTurnLeft_AngleLeft15,
                                        gTurnLeft_AngleLeft16,
                                        gGoStraight3_Distance10,
                                        gGoStraight3_Distance11,
                                        gGoStraight1_Distance12,
                                        gGoStraight1_Distance13,
                                        gGoStraight3_Distance14,
                                        gGoStraight3_Distance15,
                                        gTurnRight_AngleRight11,
                                        gGoStraight2_Distance16,
                                        gGoStraight2_Distance17,
                                        gGoStraight2_Distance18,
                                        gGoStraightBack_DistanceBack6,
                                        gGoStraightBack_DistanceBack7,
                                        gGoStraightBack_DistanceBack8,
                                        gGoStraightBack_DistanceBack9,
                                        gGoStraightBack_DistanceBack10,
                                        gGoStraightBack_DistanceBack11,
                                        gGoStraightBack_DistanceBack12,
                                        gGoStraightBack_DistanceBack13,
                                        gGoStraightBack_DistanceBack14,
                                        gTurnRight_ColorJudgeBlack  );

    gScenario5         = new Scenario(patern,5,gArmDown_ArmJudgeDown,
                                        gLineTrace_ColorJudgeRed,
                                        gTurnRight_AngleRight1,
                                        gGoStraight1_ColorJudgeBlack,
                                        gGoStraightBack_DistanceBack1,
                                        gTurnLeft_AngleLeft1,
                                        gLineTrace_ColorJudgeBlue,
                                        gGoStraight2_Distance1,
                                        gTurnRight_AngleRight2,
                                        gArmUp_ArmJudgeUp,
                                        gTurnLeft_AngleLeft2,
                                        gTurnRight_AngleRight3,
                                        gGoStraightBack_DistanceBack2,
                                        gGostraight3_Distance2,
                                        gTurnLeft_AngleLeft3,
                                        gGoStraight1_Distance3,
                                        gGoStraightBack_DistanceBack3,
                                        gLineTrace_ColorJudgeGreen,
                                        gLineTrace_ColorJudgeYellow,
                                        gTurnLeft_AngleLeft4,
                                        gTurnLeft_AngleLeft5,
                                        gGoStraight3_Distance4,
                                        gTurnLeft_AngleLeft6,
                                        gTurnRight_AngleRight4,
                                        gGoStraight1_Distance5,
                                        gTurnLeft_AngleLeft7,
                                        gTurnRight_AngleRight5,
                                        gGoStraight3_Distance6,
                                        gTurnLeft_AngleLeft8,
                                        gTurnLeft_ColorJudgeBlack,
                                        gGoStraight1_Distance7,
                                        gGoStraight1_Distance8,
                                        gTurnLeft_AngleLeft9,
                                        gGoStraight3_Distance9,
                                        gTurnLeft_AngleLeft10,
                                        gGoStraightBack_DistanceBack4,
                                        gTurnRight_AngleRight6,
                                        gGoStraightBack_DistanceBack5,
                                        gTurnRight_AngleRight7,
                                        gTurnRight_AngleRight8,
                                        gTurnRight_AngleRight9,
                                        gTurnRight_AngleRight10,
                                        gTurnLeft_AngleLeft11,
                                        gTurnLeft_AngleLeft12,
                                        gTurnLeft_AngleLeft13,
                                        gTurnLeft_AngleLeft14,
                                        gTurnLeft_AngleLeft15,
                                        gTurnLeft_AngleLeft16,
                                        gGoStraight3_Distance10,
                                        gGoStraight3_Distance11,
                                        gGoStraight1_Distance12,
                                        gGoStraight1_Distance13,
                                        gGoStraight3_Distance14,
                                        gGoStraight3_Distance15,
                                        gTurnRight_AngleRight11,
                                        gGoStraight2_Distance16,
                                        gGoStraight2_Distance17,
                                        gGoStraight2_Distance18,
                                        gGoStraightBack_DistanceBack6,
                                        gGoStraightBack_DistanceBack7,
                                        gGoStraightBack_DistanceBack8,
                                        gGoStraightBack_DistanceBack9,
                                        gGoStraightBack_DistanceBack10,
                                        gGoStraightBack_DistanceBack11,
                                        gGoStraightBack_DistanceBack12,
                                        gGoStraightBack_DistanceBack13,
                                        gGoStraightBack_DistanceBack14,
                                        gTurnRight_ColorJudgeBlack);

    

    //scenarioManager
    //ここのシナリオ管理の引数の一個目をパターンによって変更する。
    gScenarioManager  = new ScenarioManager(gColorJudgeRed,gColorJudgeBlue,gScenario1,
                                                                            gScenario2,
                                                                            gScenario3,
                                                                            gScenario4,
                                                                            gScenario5);


    gRandomWalker    = new RandomWalker(gStarter,
                                        gLineTracer,
                                        gScenarioManager);


    // 初期化完了通知
    ev3_led_set_color(LED_ORANGE);
}

/**
 * EV3システム破棄
 */
static void user_system_destroy() {
    gLeftWheel.reset();
    gRightWheel.reset();
    gLeftWheelJudge.reset();
    gRightWheelJudge.reset();
    gArm.reset();

    //unit
    delete gWalker;
    delete gLineMonitor;
    delete gStarter;

    //motion
    delete gLineTrace;
    delete gTurnLeft;
    delete gTurnRight;
    delete gArmUp;
    delete gArmDown;
    delete gGoStraight1;
    delete gGoStraight2;
    delete gGoStraightBack;

    //judge
    delete gAngleRight1;
    delete gAngleRight2;//格子内、右折用
    delete gAngleRight3;//パターン1、ゴールまでのライン調整
    delete gAngleRight4;
    delete gAngleRight5;
    delete gAngleRight6;
    delete gAngleRight7;
    delete gAngleRight8;
    delete gAngleRight9;
    delete gAngleRight10;
    delete gAngleRight11;

    delete gAngleLeft1;//ブロック侵入への調整用
    delete gAngleLeft2;//格子内、左折用
    delete gAngleLeft3;//
    delete gAngleLeft4;//
    delete gAngleLeft5;
    delete gAngleLeft6;
    delete gAngleLeft7;
    delete gAngleLeft8;
    delete gAngleLeft9;
    delete gAngleLeft10;
    delete gAngleLeft11;
    delete gAngleLeft12;
    delete gAngleLeft13;
    delete gAngleLeft14;
    delete gAngleLeft15;
    delete gAngleLeft16;

    delete gDistance1;//格子内、右折直前用
    delete gDistance2;//パターン1、一個目のブロックから直進
    delete gDistance3;
    delete gDistance4;
    delete gDistance5;
    delete gDistance6;
    delete gDistance7;
    delete gDistance8;
    delete gDistance9;
    delete gDistance10;
    delete gDistance11;
    delete gDistance12;
    delete gDistance13;
    delete gDistance14;
    delete gDistance15;
    delete gDistance16;
    delete gDistance17;
    delete gDistance18;


    delete gDistanceBack1;//ブロック侵入、後退用
    delete gDistanceBack2;//格子内、左折直前用
    delete gDistanceBack3;
    delete gDistanceBack4;
    delete gDistanceBack5;
    delete gDistanceBack6;
    delete gDistanceBack7;
    delete gDistanceBack8;
    delete gDistanceBack9;
    delete gDistanceBack10;
    delete gDistanceBack11;
    delete gDistanceBack12;
    delete gDistanceBack13;
    delete gDistanceBack14;

    delete gColorJudgeRed;
    delete gColorJudgeBlack;
    delete gColorJudgeBlue;
    delete gBlockJudge;
    //0がアップジャッジ、1がダウンジャッジ
    delete gArmJudgeUp;
    delete gArmJudgeDown;

    delete gRandomWalker;
    delete gStarter;
   
    delete gTurnLeft;
    delete gAngleRight1;
    delete gAngleLeft1;
    delete gAngleRight2;
    delete gAngleLeft2;
    delete gDistanceBack2;
    delete gColorJudgeRed;
    delete gColorJudgeBlack;
    delete gColorJudgeBlue;
    delete gColorJudgeGreen;
    delete gColorJudgeYellow;
    delete gBlockJudge;
    delete gDistance1;
    delete gDistanceBack1;
    delete gAngleRight3;


    delete gArmDown_ArmJudgeDown;
    delete gLineTrace_ColorJudgeRed;
    delete gTurnRight_AngleRight1;
    delete gGoStraight1_ColorJudgeBlack;
    delete gTurnLeft_AngleLeft1;
    delete gLineTrace_ColorJudgeBlue;
    delete gTurnRight_AngleRight2;
    delete gGoStraight2_Distance1;
    delete gGoStraightBack_DistanceBack1;
    delete gArmUp_ArmJudgeUp;
    delete gTurnLeft_AngleLeft2;
    delete gTurnRight_AngleRight3;
    delete gGoStraightBack_DistanceBack2;
    delete gGostraight3_Distance2;
    delete gTurnRight_AngleRight3;
    delete gGoStraight1_Distance3;
    delete gGoStraightBack_DistanceBack3;
    delete gLineTrace_ColorJudgeGreen;
    delete gLineTrace_ColorJudgeYellow;
    delete gTurnLeft_AngleLeft3;
    delete gTurnLeft_AngleLeft4;
    delete gTurnLeft_AngleLeft5;
    delete gGoStraight3_Distance4;
    delete gTurnLeft_AngleLeft6;
    delete gTurnRight_AngleRight4;
    delete gGoStraight1_Distance5;
    delete gTurnLeft_AngleLeft7;
    delete gTurnRight_AngleRight5;
    delete gGoStraight3_Distance6;
    delete gTurnLeft_AngleLeft8;
    delete gTurnLeft_ColorJudgeBlack;
    delete gGoStraight1_Distance7;
    delete gGoStraight1_Distance8;
    delete gTurnLeft_AngleLeft9;
    delete gGoStraight3_Distance9;
    delete gGoStraightBack_DistanceBack4;
    delete gGoStraightBack_DistanceBack5;
    delete gTurnRight_AngleRight6;
    delete gTurnRight_AngleRight7;
    delete gTurnRight_AngleRight8;
    delete gTurnRight_AngleRight9;
    delete gTurnRight_AngleRight10;
    delete gTurnLeft_AngleLeft10;
    delete gTurnLeft_AngleLeft11;
    delete gTurnLeft_AngleLeft12;
    delete gTurnLeft_AngleLeft13;
    delete gTurnLeft_AngleLeft14;
    delete gTurnLeft_AngleLeft15;
    delete gTurnLeft_AngleLeft16;
    delete gGoStraight3_Distance10;
    delete gGoStraight3_Distance11;
    delete gGoStraight1_Distance12;
    delete gGoStraight1_Distance13;
    delete gGoStraight3_Distance14;
    delete gGoStraight3_Distance15;
    delete gTurnRight_AngleRight11;
    delete gGoStraight2_Distance16;
    delete gGoStraight2_Distance17;
    delete gGoStraight2_Distance18;
    delete gGoStraightBack_DistanceBack6;
    delete gGoStraightBack_DistanceBack7;
    delete gGoStraightBack_DistanceBack8;
    delete gGoStraightBack_DistanceBack9;
    delete gGoStraightBack_DistanceBack10;
    delete gGoStraightBack_DistanceBack11;
    delete gGoStraightBack_DistanceBack12;
    delete gGoStraightBack_DistanceBack13;
    delete gGoStraightBack_DistanceBack14;


    //scenario
    delete gScenario1;
    delete gScenario2;
    delete gScenario3;
    delete gScenario4;
    delete gScenario5;


    //scenarioManager
    delete gScenarioManager;


    delete gRandomWalker;

}

/**
 * メインタスク
 */
void main_task(intptr_t unused) {
    user_system_create();  // センサやモータの初期化処理

    // 周期ハンドラ開始
    //　周期ハンドラの値は小さいとモーターのリセットが間に合わないため、要検討
    sta_cyc(CYC_TRACER);
    
    slp_tsk();  // バックボタンが押されるまで待つ

    // 周期ハンドラ停止
    stp_cyc(CYC_TRACER);

    user_system_destroy();  // 終了処理

    ext_tsk();
}

/**
 * ライントレースタスク
 */
void tracer_task(intptr_t exinf) {
    if (ev3_button_is_pressed(BACK_BUTTON)) {
        wup_tsk(MAIN_TASK);  // バックボタン押下
    } else {
        gRandomWalker->run();  // 走行
    }

    ext_tsk();
}
