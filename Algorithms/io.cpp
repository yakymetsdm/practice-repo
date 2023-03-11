#include <iostream>

int getNumber()
{
	do {
		std::cout << "Enter number: ";
		int value;
		std::cin >> value;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
		else
		{
			std::cin.ignore(32767, '\n');
			return value;
		}
	} while (true);

	return -1;
}

void initializeArray(int arr[], int size, int max, int min)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % (max - min) + min;
	}
}

void printArray(int arr[], int size)
{
	std::cout << "Your array: ";
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
