// FallingBall.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This program is simulation falling ball from tower
// Program output the height of the ball above ground, every second

#include <iostream>
#include "constants.h"
#include "functions.h"

int main()
{
    int initHeight = getInitHeight();//Initial height
    int seconds = 0;                 //Time from start fall
    double currentHeight;            //Height in specific time moment

    if (initHeight == 0)
    {
        std::cout << "Ball on the ground." << std::endl;
    }
    else
    {
        do
        {
            currentHeight = calculateHeight(initHeight, seconds);
            printHeight(currentHeight, seconds);
            ++seconds;
        } while (currentHeight > 0.0);
    }

    return 0;
}
