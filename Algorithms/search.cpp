
int findMax(int arr[], int size)
{
	int element = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (element < arr[i])
			element = arr[i];
	}
	return element;
}

int findMin(int arr[], int size)
{
	int element = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (element > arr[i])
			element = arr[i];
	}
	return element;
}

int linearSearch(int arr[], int size, int value)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == value)
			return i;
	}

	return -1;
}

int sentinelLinearSearch(int arr[], int size, int value)
{
	int lastElement = arr[size - 1];
	arr[size - 1] = value;

	int i = 0;
	while (arr[i] != value)
		i++;

	arr[size - 1] = lastElement;

	if (i < (size - 1) || (arr[size - 1] == value))
		return i;

	return -1;
}

int binarySearch(int arr[], int size, int value, char dir)
{
	int leftEdge = 0, rightEdge = size - 1;

	if (dir == 'a')
	{
		do
		{
			int middle = (leftEdge + rightEdge) / 2;

			if (arr[middle] > value)
				rightEdge = middle - 1;
			else if (arr[middle] < value)
				leftEdge = middle + 1;
			else
				return middle;

		} while (leftEdge <= rightEdge);

	}
	else
	{
		do
		{
			int middle = (leftEdge + rightEdge) / 2;

			if (arr[middle] > value)
				leftEdge = middle + 1;
			else if (arr[middle] < value)
				rightEdge = middle - 1;
			else
				return middle;

		} while (leftEdge <= rightEdge);

	}

	return -1;
}