
//*****************************
// Class for one round's score and its properties.
//*****************************

#include "ScoreOfEachRound.h"

//*****************************
// constructor
//*****************************
ScoreOfEachRound::ScoreOfEachRound(int first, int second, int third)
{
	FirstHit = first;
	SecondHit = second;
	ThirdHit = third;

	RoundType_obj = NORMAL_ROUND;

	maxscoreInOneRound = 10;
}

//*****************************
// Destructor
//*****************************
ScoreOfEachRound::~ScoreOfEachRound() {}

//*****************************
// this method is finding, the current round is a normal, spare or strike type.
//*****************************
bool ScoreOfEachRound::classifiedThisRound()
{
	if (FirstHit == maxscoreInOneRound)
		RoundType_obj = STRIKE_ROUND;
	else if ((FirstHit + SecondHit) == maxscoreInOneRound)
		RoundType_obj = SPARE_ROUND;

	return true;
}