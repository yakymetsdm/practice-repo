// Algorithms.cpp : This project contains realization of some algorithms.

#include <iostream>
#include <ctime>
#include "io.h"
#include "SearchAlgorithms.h"
#include "SortAlgorithms.h"


int main()
{
	srand(static_cast<unsigned>(time(0)));

	const int size = 10;
	int numbers[size]{ 0 };

	initializeArray(numbers, size, 50);
	printArray(numbers, size);

	int maxElement = findMax(numbers, size);
	std::cout << "Max element is: " << maxElement << std::endl;

	int minElement = findMin(numbers, size);
	std::cout << "Min element is: " << minElement << std::endl;

	std::cout << "\nLet's find some elements in this array." << std::endl;
	int value_1 = getNumber();
	int elemIndex_1 = linearSearch(numbers, size, value_1);

	if (elemIndex_1 != -1)
		std::cout << "Element " << value_1 << " find at " << elemIndex_1 << " index.";
	else
		std::cout << "Array does not contains number " << value_1;
	std::cout << std::endl;

	int value_2 = getNumber();
	int elemIndex_2 = sentinelLinearSearch(numbers, size, value_2);

	if (elemIndex_2 != -1)
		std::cout << "Element " << value_2 << " find at " << elemIndex_2 << " index.";
	else
		std::cout << "Array does not contains number " << value_2;
	std::cout << std::endl;


	std::cout << "\nSELECTION Sort" << std::endl;
	char sortDir = sortDirection();
	selectionSort(numbers, size, sortDir);
	printArray(numbers, size);


	std::cout << "\nINSERTION Sort" << std::endl;
	sortDir = sortDirection();
	insertionSort(numbers, size, sortDir);
	printArray(numbers, size);


	std::cout << "\nBUBBLE Sort" << std::endl;
	sortDir = sortDirection();
	bubbleSort(numbers, size, sortDir);
	printArray(numbers, size);


	std::cout << "\nQUICK Sort" << std::endl;
	sortDir = sortDirection();
	quickSort(numbers, 0, size - 1, sortDir);
	printArray(numbers, size);

	std::cout << "\nBINARY Search" << std::endl;
	int value_3 = getNumber();
	int elemIndex_3 = binarySearch(numbers, size, value_3, sortDir);

	if(elemIndex_3 != -1)
		std::cout << "Element " << value_3 << " find at " << elemIndex_3 << " index.";
	else
		std::cout << "Array does not contains number " << value_3;
	std::cout << std::endl;

	return 0;
}


