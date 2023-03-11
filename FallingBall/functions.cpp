#include <iostream>
#include "constants.h"

const double g = myConstants::gravity;

//This funciton get from user height of tower
int getInitHeight()
{
	while (true)
	{
		std::cout << "Enter initial height: ";
		int initHeight;
		std::cin >> initHeight;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Ooops, something went wrong. Please try again." << std::endl;
		}
		else if (initHeight < 0)
		{
			std::cin.ignore(32767, '\n');
			std::cout << "Oops, ball can not be under the ground. Please try again." << std::endl;
		}
		else
		{
			std::cin.ignore(32767, '\n');
			return initHeight;
		}
	}
}

//This funciton calculate the height in the free fall
double calculateHeight(int initHeight, int t)
{
	double currentHeight = initHeight - (g * ((static_cast<double>(t) * static_cast<double>(t)) / 2));

	return currentHeight;
}

//This funciton output height at specified interval of time
void printHeight(double height, int t)
{
	if (height > 0)
	{
		std::cout << "After " << t << " seconds, the ball at height " << height << " meters." << std::endl;
	}
	else
	{
		std::cout << "After " << t << " seconds, the ball on the ground." << std::endl;
	}
}
