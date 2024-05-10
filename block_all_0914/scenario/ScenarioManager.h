#ifndef EV3_SCENARIO_SCENARIOMANAGER_H_
#define EV3_SCENARIO_SCENARIOMANAGER_H_

#include "Scenario.h"
#include "Checker.h"

class ScenarioManager {
public:
    ScenarioManager(Checker* colorRed,Checker* colorBlue,Scenario* scenario1,
                                                                    Scenario* scenario2,
                                                                    Scenario* scenario3,
                                                                    Scenario* scenario4,
                                                                    Scenario* scenario5);

    bool run();
    Checker* mColorJudgeRed;
    Checker* mColorJudgeBlue;
    Scenario* mScenario1;
    Scenario* mScenario2;
    Scenario* mScenario3;
    Scenario* mScenario4;
    Scenario* mScenario5;


private:

};

#endif  
