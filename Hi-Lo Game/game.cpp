// Hi-Lo Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "functions.h"


int main()
{
    srand(static_cast<unsigned int>(time(0)));
    rand();

    int guesses = 7;

    do
    {
        int number = getRandomNumber(1, 100);
        bool gameTurn = playGame(guesses, number);

        if (gameTurn)
        {
            std::cout << "Correct! You win!" << std::endl;
        }
        else
        {
            std::cout << "Sorry, you lose! The correcr number was " << number << std::endl;
        }

    } while (playAgain());

    std::cout << "Thanks for playing!" << std::endl;

    return 0;
}
