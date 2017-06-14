#include "stdafx.h"
#include <iostream>
using namespace std;

template <typename T>
T* merge(T* leftArray, T* rightArray, int leftSize,  int rightSize)
{
	int leftIndex = 0;
	int rightIndex = 0;
	int resultIndex = 0;
	
	T* result = new T[leftSize + rightSize];
	while (leftIndex < leftSize && rightIndex < rightSize)
	{
		if (leftArray[leftIndex] < rightArray[rightIndex])
		{
			result[resultIndex] = leftArray[leftIndex];
			resultIndex++;
			leftIndex++;
		}

		if (leftArray[leftIndex] >= rightArray[rightIndex])
		{
			result[resultIndex] = rightArray[rightIndex];
			resultIndex++;
			rightIndex++;
		}
	}

	while (leftIndex < leftSize)
	{
		result[resultIndex] = leftArray[leftIndex];
		resultIndex++;
		leftIndex++;
	}

	while (rightIndex < rightSize)
	{
		result[resultIndex] = rightArray[rightIndex];
		resultIndex++;
		rightIndex++;
	}

	return result;
}


template <typename T>
T* MergeSort(T *array, int size)
{
	if (size < 2)
	{
		return array;
	}

	int leftSize = size - size / 2;
	int rightSize = size / 2;

	T* leftArray = new T[leftSize];
	T* rightArray = new T[rightSize];

	for (size_t i = 0; i < leftSize; i++)
	{
		leftArray[i] = array[i];
	}

	int rightIndex = leftSize;
	for (size_t i = 0; i < rightSize; i++)
	{
		rightArray[i] = array[rightIndex];
		rightIndex++;
	}

	T* sortedLeftArray = MergeSort(leftArray, leftSize);
	T* sortedRightArray = MergeSort(rightArray, rightSize);

	return merge(sortedLeftArray, sortedRightArray, leftSize,  rightSize);
}
