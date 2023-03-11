// ScoresJournal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

struct Student
{
	std::string name = "";
	int score{ 0 };
};

void sortScores(Student *arr, int length)
{
	for (int i = 0; i < length; ++i)
	{
		int highest_index = i;

		for (int j = i + 1; j < length; ++j)
		{
			if (arr[j].score > arr[highest_index].score)
			{
				highest_index = j;
			}
		}
		std::swap(arr[highest_index], arr[i]);
	}
}

int main()
{
	int number_of_students = 0;

	while (number_of_students <= 1)
	{
		std::cout << "Enter number of students: ";
		std::cin >> number_of_students;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
		else
		{
			std::cin.ignore(32767, '\n');
		}
	}

	Student* students = new Student[number_of_students];

	for (int i = 0; i < number_of_students; ++i)
	{
		while (students[i].name == "")
		{
			std::cout << "Enter student #" << i + 1 << " name: ";
			std::cin >> students[i].name;

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
			}
			else
			{
				std::cin.ignore(32767, '\n');
			}
		}
		
		while (students[i].score <= 0)
		{
			std::cout << "Enter student #" << i + 1 << " score: ";
			std::cin >> students[i].score;

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
			}
			else
			{
				std::cin.ignore(32767, '\n');
			}
		}
	}
	std::cout << std::endl;

	sortScores(students, number_of_students);

	for (int i = 0; i < number_of_students; ++i)
	{
		std::cout << students[i].name << " has score " << students[i].score << std::endl;
	}

	delete[] students;

	return 0;
}

