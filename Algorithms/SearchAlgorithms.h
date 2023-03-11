#pragma once
#ifndef SEARCH_ALGORITHMS
#define SEARCH_ALGORITHMS

int findMax(int arr[], int size);
int findMin(int arr[], int size);
int linearSearch(int arr[], int size, int value);
int sentinelLinearSearch(int arr[], int size, int value);
int binarySearch(int arr[], int size, int value, char dir = 'a');

#endif // !SEARCH_ALGORITHMS

