#include <iostream>

void BubbleSort1(int* arr, int n)
{
	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1; j < n; ++j)
			if (arr[j] < arr[i]) 
				std::swap(arr[i], arr[j]);
}
/*
* ADAPTIVE BUBBLE SORT:
* Can early break if already sorted. 
*/
void BubbleSort(int* arr, int n)
{
	bool swapped;
	for (int i = 0; i < n - 1; ++i)
	{
		swapped = false;
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[j] < arr[i])
			{
				std::swap(arr[i], arr[j]);
				swapped = true;
			}
		}
		if (!swapped) break;
	}
}

int main(int argc, char* argv[])
{
	int n = atoi(argv[1]), * arr = new int[n];
	for (int i = 0; i < n; ++i)std::cin >> arr[i];

	// BubbleSort1(arr, n);
	BubbleSort(arr, n);

	for (int i = 0; i < n; ++i)std::cout << arr[i] << " ";
}