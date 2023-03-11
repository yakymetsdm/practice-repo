#pragma once
#ifndef SORT_ALGORITHMS
#define SORT_ALGORITHMS

#include <string>

char sortDirection();
void selectionSort(int arr[], int size, char dir = 'a');
void insertionSort(int arr[], int size, char dir = 'a');
void bubbleSort(int arr[], int size, char dir = 'a');
void quickSort(int arr[], int first, int last, char dir = 'a');

#endif // !SORT_ALGORITHMS

