mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_CXXOBJS += \
	GoStraight.o \
	Turn.o \
	RandomWalker.o \
	Starter.o \
	Angle.o \
	Distance.o \
	Scene.o \
	Scenario.o \
	Motion.o \
	Checker.o \
	Arm.o \
	ArmJudge.o \
	ColorJudge.o \
	LineMonitor.o \
	Walker.o \
	LineTrace.o \
	LineTracer.o \
	StraightCtrl.o \
	ScenarioManager.o \
	BlockJudge.o

SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile

endif

APPL_DIRS += $(mkfile_path)app $(mkfile_path)unit $(mkfile_path)motion $(mkfile_path)judge $(mkfile_path)scenario

INCLUDES += \
	-I$(mkfile_path)app \
	-I$(mkfile_path)unit \
	-I$(mkfile_path)motion \
	-I$(mkfile_path)judge \
	-I$(mkfile_path)scenario \
	

