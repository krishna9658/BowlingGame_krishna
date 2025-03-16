//*****************************
// This class is meant for calculating all scores and applying bonus score and other logics.
//*****************************
#include "enum.cpp"
#include "CalculateScore.h"

//*****************************
// Constructor
//*****************************
CalculateScore::CalculateScore()
{
	finalScore = 0;
	previousRoundType = NORMAL_ROUND;
}

//*****************************
// Destructor
//*****************************
CalculateScore::~CalculateScore() {}

//*****************************
// This method is handling all steps
//*****************************
bool CalculateScore::calculateFinalScore(const ScoreOfEachRound& Current_ScoreOfEachRound)
{

	addBonusForPreviousRound(Current_ScoreOfEachRound);
	addScoreForcurrentRound(Current_ScoreOfEachRound);
	updateCurrentRoundType(Current_ScoreOfEachRound);

	return true;
}

//*****************************
// This method is returning final score.
//*****************************
int CalculateScore::getScore()
{
	return finalScore;
}

//*****************************
// This method is adding bonus score according to previous round.
//*****************************
bool CalculateScore::addBonusForPreviousRound(const ScoreOfEachRound& Current_ScoreOfEachRound)
{
	if (previousRoundType == SPARE_ROUND)
		finalScore += Current_ScoreOfEachRound.FirstHit;
	else if (previousRoundType == STRIKE_ROUND)
		finalScore += Current_ScoreOfEachRound.FirstHit + Current_ScoreOfEachRound.SecondHit;

	return true;
}

//*****************************
// This method is adding score for current round.
//*****************************
bool CalculateScore::addScoreForcurrentRound(const ScoreOfEachRound& Current_ScoreOfEachRound)
{
	finalScore += Current_ScoreOfEachRound.FirstHit + Current_ScoreOfEachRound.SecondHit + Current_ScoreOfEachRound.ThirdHit;

	return true;
}

//*****************************
// This method is preserving current round type for future porpose.
//*****************************
bool CalculateScore::updateCurrentRoundType(const ScoreOfEachRound& Current_ScoreOfEachRound)
{
	previousRoundType = Current_ScoreOfEachRound.RoundType_obj;

	return true;
}