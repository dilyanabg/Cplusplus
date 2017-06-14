#include "stdafx.h"
#include <iostream>
using namespace std;

template<typename T>
void swapItems(T &first, T &second)
{
	T temp = first;
	first = second;
	second = temp;
}

template<typename T>
int partition(T *array, int start, int end)
{
	T pivot = array[end];
	int pivotIndex = start;

	for (size_t i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			swapItems(array[i], array[pivotIndex]);
			pivotIndex++;
		}
	}
	swapItems(array[pivotIndex], array[end]);
	return pivotIndex;
}

template<typename T>
void QuickSort(T *array, int start, int end)
{
	if (start >= end) return;

	int pivotIndex = partition(array, start, end);
	QuickSort(array, start, pivotIndex - 1);
	QuickSort(array, pivotIndex + 1, end);
}

int main()
{
	int array[] = { 5, 14, 2, -3, 0, 8, 11, 7, 1, -1 };

	int start = 0;
	int end = sizeof(array) / sizeof(*array);

	QuickSort<int>(array, start, end - 1);
	for (size_t i = 0; i < 10; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
    return 0;
}

