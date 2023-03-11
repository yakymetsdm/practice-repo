#include <iostream>
#include <cstdlib>

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

	return static_cast<int>(rand() * fraction * (static_cast<double>(max) - static_cast<double>(min) + 1) + min);
}

bool playGame(int turns, int answer)
{
	std::cout << "Let's play the game. I'm thinking of a number. You have 7 tries to guess what it is." << std::endl;
	int guess;
	for (int i = 1; i <= turns; ++i)
	{
		std::cout << "Guess #" << i << ": ";
		std::cin >> guess;
		//std::cin.ignore(32767, '\n');
		
		if (guess > answer)
		{
			std::cout << "Your prediction is too high." << std::endl;
		}
		else if (guess < answer)
		{
			std::cout << "Your prediction is too low." << std::endl;
		}
		else
		{
			return true;
		}
	}
	return false;
}

bool playAgain()
{
	char ch;
	do
	{
		std::cout << "Would you like to play again (y/n)? ";
		std::cin >> ch;
		std::cin.ignore(32767, '\n');
	} while (ch != 'y' && ch != 'n');
	
	return (ch == 'y');
}