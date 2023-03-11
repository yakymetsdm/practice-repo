#include <iostream>
#include <string>

char sortDirection()
{
	//'a' - ascending, 'd' - descending
	char sortDirection;

	do
	{
		std::cout << "Enter sort direction, for ascending type - a, for descending type - d: ";
		std::cin >> sortDirection;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
		else if (sortDirection == 'a' || sortDirection == 'd')
		{
			std::cin.ignore(32767, '\n');
			return sortDirection;
		}
	} while (1);

	return '0';
}

void selectionSort(int arr[], int size, char dir)
{
	int startElem, startIndex;

	if (dir == 'a')
	{
		for (int i = 0; i < size - 1; i++)
		{
			startIndex = i;
			startElem = arr[i];

			for (int j = i + 1; j < size; j++)
			{
				if (startElem > arr[j])
				{
					startElem = arr[j];
					startIndex = j;
				}
			}
			std::swap(arr[i], arr[startIndex]);
		}
	}
	else
	{
		for (int i = 0; i < size - 1; i++)
		{
			startIndex = i;
			startElem = arr[i];

			for (int j = i + 1; j < size; j++)
			{
				if (startElem < arr[j])
				{
					startElem = arr[j];
					startIndex = j;
				}
			}
			std::swap(arr[i], arr[startIndex]);
		}
	}
}

void insertionSort(int arr[], int size, char dir)
{
	if (dir == 'a')
	{
		for (int i = 1; i < size; i++)
		{
			int key = arr[i];

			int j;
			for (j = i - 1; j >= 0 && arr[j] > key; j--)
				arr[j + 1] = arr[j];

			arr[j + 1] = key;
		}
	}
	else
	{
		for (int i = 1; i < size; i++)
		{
			int key = arr[i];

			int j;
			for (j = i - 1; j >= 0 && arr[j] < key; j--)
				arr[j + 1] = arr[j];

			arr[j + 1] = key;
		}
	}
}

void bubbleSort(int arr[], int size, char dir)
{
	if (dir == 'a')
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size - 1; j++)
			{
				if (arr[j] > arr[j + 1])
					std::swap(arr[j], arr[j + 1]);
			}
		}
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size - 1; j++)
			{
				if (arr[j] < arr[j + 1])
					std::swap(arr[j], arr[j + 1]);
			}
		}
	}


}

void quickSort(int arr[], int first, int last, char dir)
{
	int middle = arr[(first + last) / 2];
	int i = first, j = last;

	if (dir == 'a')
	{
		do
		{
			while (arr[j] > middle)	j--;
			while (arr[i] < middle) i++;

			if (i <= j)
			{
				std::swap(arr[i], arr[j]);
				i++;
				j--;
			}
		} while (i <= j);

		if (j > first)
			quickSort(arr, first, j, dir);

		if (i < last)
			quickSort(arr, i, last, dir);
	}
	else
	{
		do
		{
			while (arr[j] < middle)	j--;
			while (arr[i] > middle) i++;

			if (i <= j)
			{
				std::swap(arr[i], arr[j]);
				i++;
				j--;
			}
		} while (i <= j);

		if (j > first)
			quickSort(arr, first, j, dir);

		if (i < last)
			quickSort(arr, i, last, dir);
	}
}