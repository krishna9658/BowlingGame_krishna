//*****************************
// Class for one round's score and its properties.
//*****************************

#pragma once

#include "enum.cpp"

class ScoreOfEachRound
{

	int maxscoreInOneRound;
public:

	int FirstHit, SecondHit, ThirdHit;
	RoundType RoundType_obj;

	ScoreOfEachRound();
	ScoreOfEachRound(int first, int second, int third);
	~ScoreOfEachRound();

	bool classifiedThisRound();
};
