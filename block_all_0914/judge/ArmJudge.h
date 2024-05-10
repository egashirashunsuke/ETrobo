#ifndef EV3_JUDGE_ARMJUDGE_H
#define EV3_JUDGE_ARMJUDGE_H


#include "Motor.h"
#include "Checker.h"
//#include ".h"
//アーム角度

class ArmJudge : public Checker{
	private:
		ev3api::Motor& mArm;

		int16_t mTargetArm;
		int16_t angle;
		int mTurn;

		//デバイス::アームモータ アームモータ;]
		//ev3api::Motor& armmoter

	public:
		ArmJudge(int16_t targetarm,ev3api::Motor& Arm,int turn);

		bool judge() override;

		void init () override;
};
#endif
