#include <iostream>
using namespace std;

#pragma region InsertionSort
void insertion_sort(int A[], int n)
{
	int key , i;
	for (int j = 1; j < n; j++)
	{
		key = A[j];
		i = j - 1;
		while (i >= 0 && A[i] > key)
		{
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
	}
}
#pragma endregion
#pragma region MergeSort
void merge(int A[], int left, int mid, int right)
{
	int subArrayOne = mid - left + 1;
	int subArrayTwo = right - mid;
	int* leftArray = new int[subArrayOne],
		* rightArray = new int[subArrayTwo];
	for (int i = 0; i < subArrayOne; i++)
		leftArray[i] = A[left + i];
	for (int j = 0; j < subArrayTwo; j++)
		rightArray[j] = A[mid + 1 + j];

	int indexOfSubArrayOne = 0;
	int indexOfSubArrayTwo = 0;
	int indexOfMergedArray = left;

	// Merge

	while(indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo <subArrayTwo)
	{
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
		{
			A[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else
		{
			A[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	while (indexOfSubArrayOne < subArrayOne)
	{
		A[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	while (indexOfSubArrayTwo < subArrayTwo)
	{
		A[indexOfMergedArray] = leftArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
	delete[] leftArray;
	delete[] rightArray;
}


void merge_sort(int A[], int begin, int end)
{
		if (begin >= end)
			return;
		int mid = begin + (end - begin) / 2;

		merge_sort(A, begin, mid);
		merge_sort(A, mid + 1, end);

		merge(A, begin, mid, end);
	
}
#pragma endregion


void display(int A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}
int main()
{
	cout << "1) insertion sort\n2) merge sort\n";
	int type;
	cin >> type;
	if (type == 1)
	{
		int arr1[] = { 5,2,10,9,1,3,8,6,4,7 };
		insertion_sort(arr1, 10);
		display(arr1, 10);

		int arr2[] = { 10,9,8,7,6,5,4,3,2,1 };
		insertion_sort(arr2, 10);
		display(arr2, 10);

		int arr3[] = { 1,2,3,4,5,6,7,8,9,10 };
		insertion_sort(arr3, 10);
		display(arr3, 10);
	}
	else if (type == 2)
	{
		int arr4[] = { 5,2,10,9,1,3,8,6,4,7 };
		int arrSize = sizeof(arr4) / sizeof(arr4[0]);
		merge_sort(arr4, 0, arrSize-1);
		display(arr4, arrSize);

		int arr5[] = { 10,9,8,7,6,5,4,3,2,1 };
		merge_sort(arr5, 0, 9);
		display(arr5, 10);

		int arr6[] = { 1,2,3,4,5,6,7,8,9,10 };
		merge_sort(arr6, 0, 9);
		display(arr6, 10);
	}
}
