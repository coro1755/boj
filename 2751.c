#include <iostream>
using namespace std;


void MergeTwoArea(int *arr, int left, int mid, int right);
void MergeSort(int *arr, int left, int right);

int main()
{
	int N = 0;
	scanf("%d", &N);
	int *arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	MergeSort(arr, 0, N - 1);
	for (int i = 0; i < N; i++)
	{
		printf("%d\n", arr[i]);
	}
	delete[] arr;
	return 0;
}

void MergeTwoArea(int *arr, int left, int mid, int right)
{
	int fIdx = left;
	int rIdx = mid + 1;
	int *sortArr = new int[right + 1];
	int sIdx = left;
	while (fIdx <= mid && rIdx <= right)
	{
		if (arr[fIdx] <= arr[rIdx])
		{
			sortArr[sIdx] = arr[fIdx++];
		}
		else
		{
			sortArr[sIdx] = arr[rIdx++];
		}
		sIdx++;
	}
	if (fIdx > mid)
	{
		for (int i = rIdx; i <= right; i++, sIdx++)
		{
			sortArr[sIdx] = arr[i];
		}
	}
	else
	{
		for (int i = fIdx; i <= mid; i++, sIdx++)
		{
			sortArr[sIdx] = arr[i];
		}
	}

	for (int i = left; i <= right; i++)
	{
		arr[i] = sortArr[i];
	}
	delete[] sortArr;
}

void MergeSort(int *arr, int left, int right)
{
	int mid = (left + right) / 2;

	if (left < right)
	{
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		MergeTwoArea(arr, left, mid, right);
	}
}

