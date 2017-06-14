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

void heapify(int array[], int size, int wall)
{
	if (wall >= 0) // това май е излишно
	{
		size_t j = 0;

		swapItems(array[j], array[wall-1]);
		wall--;

		while (j < wall && (array[j] < array[2 * j + 1] || array[j] < array[2 * j + 2]))
		{
			if (array[2 * j + 1] < array[2 * j + 2])
			{
				if ((2 * j + 2) >= wall)
					break;

				swapItems(array[j], array[2 * j + 2]);
				j = 2 * j + 2;
			}

			else
			{
				if ((2 * j + 1) >= wall)
					break;

				swapItems(array[j], array[2 * j + 1]);
				j = 2 * j + 1;
			}
		}
	}
}

void HeapSort(int array[], int size)
{
	size_t wall = size;

	for (size_t i = 0; i < size; i++)
	{
		heapify(array, size, wall);
		wall--;

		if (wall == 1)
			break;
	}
	
	if (wall == 1)
	{
		if (array[wall] < array[wall - 1])
		{
			swapItems(array[wall], array[wall-1]);
		}
	}
}

int main()
{
	int array[] = { 88, 85, 83, 72, 73, 42, 57, 6, 48, 60 }; 
	
	int size = sizeof(array) / sizeof(*array);

	HeapSort(array, size);

	for (size_t i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

    return 0;
}

