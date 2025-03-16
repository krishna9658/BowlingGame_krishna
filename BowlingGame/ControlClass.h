//*****************************
//class for controlling whole programe.
//*****************************

#include <vector>

#include "CalculateScore.h"

class ControlClass
{

	vector<int> InputVec;
	int maxSizeInpurArray;
	int minSizeInpurArray;
	int maxScoreInOneRound;
	int maxRound;

	CalculateScore obj_CalculateScore;

	bool getInPutData();
	bool validateInput();
	bool calculateResult();

public:

	ControlClass();
	~ControlClass();

	bool controlAllSteps();
	int  getFinalscore();
};
