// BowlingGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "ControlClass.h"


int main()
{

    ControlClass obj_ControlClass;

    if (obj_ControlClass.controlAllSteps())
    {
        cout << "This is the final score: " << obj_ControlClass.getFinalscore();
    }
    else
    {
        cout << "Failed to calculate final score. \n";
    }

    return 0;
}

