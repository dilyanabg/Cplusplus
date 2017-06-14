#include "stdafx.h"
#include <iostream>
using namespace std;

template <typename T>
void InsertionSort(T *array, int size )
{
	for (size_t i = 1; i < size; i++)
	{
		T element = array[i];
		size_t j = i;

		while (j > 0 && array[j - 1] > element)
		{
			array[j] = array[j - 1];
			j = j - 1;
		}
		array[j] = element;
	}
}
