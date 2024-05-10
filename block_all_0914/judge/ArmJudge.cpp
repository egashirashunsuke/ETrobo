#include "ArmJudge.h"


ArmJudge::ArmJudge(int16_t targetarm,ev3api::Motor& Arm,int turn)
	:mTargetArm(targetarm),
	 mArm(Arm),
	 mTurn(turn){
	
}

//0がアップジャッジ、1がダウンジャッジ

bool ArmJudge::judge(){
	angle = mArm.getCount();
	printf("アームの角位置：%d\n", angle);
	if (mTurn == 1){
		if (angle > mTargetArm){
		return true;
	}else{
		return false;
	}
	}else if(mTurn == 0){
		if (angle < mTargetArm){
		return true;
	}else{
		return false;
	}
	}
}

void ArmJudge::init(){
	mArm.reset();
}
