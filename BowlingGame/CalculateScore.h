//*****************************
// This class is meant for calculating all scores and applying bonus score and other logics.
//*****************************
#include "ScoreOfEachRound.h"

class CalculateScore
{
	int finalScore;

	RoundType previousRoundType;

	bool addBonusForPreviousRound(const ScoreOfEachRound& Current_ScoreOfEachRound);
	bool addScoreForcurrentRound(const ScoreOfEachRound& Current_ScoreOfEachRound);
	bool updateCurrentRoundType(const ScoreOfEachRound& Current_ScoreOfEachRound);

public:

	CalculateScore();
	~CalculateScore();

	bool calculateFinalScore(const ScoreOfEachRound& Current_ScoreOfEachRound);
	int  getScore();
};