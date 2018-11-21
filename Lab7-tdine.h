// Lab7-tdine.h
// Trevor Dine
// COSC 2030
// 17 November 2018
// Lab 7

#ifndef LAB_7_TDINE_H
#define LAB_7_TDINE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "RandomUtilities.h"
#include "winTimer.h"

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::vector;

vector<double> getNums(size_t listSize, double minNum, double maxNum)
{
	vector<double> theList;
	for (size_t i = 0; i < listSize; ++i)
	{
		theList.push_back(randReal(minNum, maxNum));
	}

	sort(begin(theList), end(theList));

	return theList;
}

void bubbleSort(vector<int> &newVec, int n)
{
	bool swapped;
	for (int i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (newVec.at(j) > newVec.at(j + 1))
			{
				int temp = newVec[j];
				newVec[j] = newVec[j + 1];
				newVec[j + 1] = temp;
				swapped = true;
			}
		}

		if (swapped == false)
		{
			break;
		}
	}
}

void insertionSort(vector<int> &newVec, int n)
{
	int key, j;

	for (int i = 1; i < n; i++)
	{
		key = newVec[i];
		j = i - 1;

		while (j >= 0 && newVec[j] > key)
		{
			newVec[j + 1] = newVec[j];
			j = j - 1;
		}

		newVec[j + 1] = key;
	}
}

void selectionSort(vector<int> &newVec, int n)
{
	int min_idx;

	for (int i = 0; i < n - 1; i++)
	{
		min_idx = i;

		for (int j = i + 1; j < n; j++)
		{
			if (newVec[j] < newVec[min_idx])
			{
				min_idx = j;
			}
		}

		int temp = newVec[min_idx];
		newVec[min_idx] = newVec[i];
		newVec[i] = temp;
	}
}

void merge(vector<int> &newVec, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	vector<int> L(newVec.size()), R(newVec.size());

	for (i = 0; i < n1; i++)
	{
		L[i] = newVec[l + i];
	}
	for (j = 0; j < n2; j++)
	{
		R[j] = newVec[m + 1 + j];
	}

	i = 0;
	j = 0;
	k = l;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			newVec[k] = L[i];
			i++;
		}
		else
		{
			newVec[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		newVec[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		newVec[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(vector<int> &newVec, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		mergeSort(newVec, l, m);
		mergeSort(newVec, m + 1, r);

		merge(newVec, l, m, r);
	}
}

int partition(vector<int> &newVec, int low, int high)
{
	int pivot = newVec[high];
	int i = (low - 1);

	for (int j = low; j < high; j++)
	{
		if (newVec[j] <= pivot)
		{
			i++;
			int temp = newVec[i];
			newVec[i] = newVec[j];
			newVec[j] = temp;
		}
	}

	int temp = newVec[i + 1];
	newVec[i + 1] = newVec[high];
	newVec[high] = temp;
	return (i + 1);
}

void quickSort(vector<int> &newVec, int low, int high)
{
	if (low < high)
	{
		int pi = partition(newVec, low, high);

		quickSort(newVec, low, pi - 1);
		quickSort(newVec, pi + 1, high);
	}
}

#endif