
//*****************************
//class for controlling whole programe.
//*****************************

#include <iostream>
#include "ControlClass.h"
#include "ScoreOfEachRound.h"

using namespace std;

//*****************************
// constructor
//*****************************
ControlClass::ControlClass()
{
	maxSizeInpurArray = 21;
	minSizeInpurArray = 20;
	maxScoreInOneRound = 10;
	maxRound = 10;
}

//*****************************
// Destructor
//*****************************
ControlClass::~ControlClass() {}

//*****************************
// This method is controlling all steps
//*****************************
bool ControlClass::controlAllSteps()
{
	if (!getInPutData())
		return false;

	if (!validateInput())
		return false;

	if (!calculateResult())
		return false;
	
	return true;
}

//*****************************
// This method is returning final score.
//*****************************
int ControlClass::getFinalscore()
{
	return obj_CalculateScore.getScore();
}

//*****************************
// This method is getting date from console.
//*****************************
bool ControlClass::getInPutData()
{
	cout << "Enter input score array:" << "\n";
	cout << "(After entering all data kindly enter -1 or Enter minimum of 20 and maximum of 21 data.)" << "\n";
	cout << "(Kindly enter score in between 0 to 10.)" << "\n";

	int count = 0;

	while (count < maxSizeInpurArray)
	{
		count++;
		int intputNo;

		cin >> intputNo;

		//if input number is greater than 10.
		if (intputNo > 10)
		{
			count--;
			cout << "Kindly enter valid inout. (0 to 10) \n";
			continue;
		}

		//if input number is less than 10, we have to close to get data from user.
		if (intputNo < 0)
		{
			count--;
			cout << "You have entered " << count << " data." << "\n";
			break;
		}

		//store all data in our vector.
		InputVec.push_back(intputNo);

		//showing the how many data we got.
		if (count == maxSizeInpurArray)
		{
			cout << "You have entered " << maxSizeInpurArray << " data." << "\n";
			break;
		}
	}

	//printing the input datas.
	cout << "Your have entered: ";
	for (int count = 0; count < InputVec.size(); count++)
	{
		cout << InputVec[count] << " ";
	}

	cout << "\n";

	return true;
}

//*****************************
// This method is validating all data, those are correct or not.
//*****************************
bool ControlClass::validateInput()
{
	size_t arraySize = InputVec.size();

	//if array size is 0.
	if (arraySize == 0)
	{
		cout << "You have entered zero data." << "\n";
		return false;
	}

	//if array size is less than 20.
	if (arraySize < minSizeInpurArray)
	{
		cout << "You have entered less than 20 data." << "\n";
		return false;
	}

	// if array size is 21 but sum of final round score is not 10.
	if (arraySize == maxSizeInpurArray && (InputVec[18] + InputVec[19]) != maxScoreInOneRound)
	{
		cout << "You have entered invalid data for last round." << "\n";
		return false;
	}

	// if array size is 20 but sum of final round score is 10.
	if (arraySize == minSizeInpurArray && (InputVec[18] + InputVec[19]) == maxScoreInOneRound)
	{
		cout << "You have to entered one more data for last round." << "\n";
		return false;
	}

	return true;
}

//*****************************
// This method is sending data to other class to calculate final score.
//*****************************
bool ControlClass::calculateResult()
{
	int roundCount = 0;
	int arrayCount = 0;

	while (arrayCount < InputVec.size())
	{
		roundCount++;

		int firstScore = InputVec[arrayCount];
		arrayCount++;
		int secondScore = InputVec[arrayCount];
		arrayCount++;

		int thirdScore = 0;

		// if it is the 10th round and still we have a extra data in our array, we have to set in our third variable.
		if (roundCount == maxRound && arrayCount < InputVec.size())  
		{
			thirdScore = InputVec[arrayCount];
			arrayCount++;
		}

		//Creation object for each rounds with their scores.
		ScoreOfEachRound obj_ScoreOfEachRound(firstScore, secondScore, thirdScore);
		obj_ScoreOfEachRound.classifiedThisRound();

		//Sending upper object to calculate the score, to CalculateScore class.
		obj_CalculateScore.calculateFinalScore(obj_ScoreOfEachRound);
	}

	return true;
}
