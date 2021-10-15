#include <iostream>

void BubbleSort(int* arr, int n)
{
	for (int i = 0; i < n-1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[j] < arr[i]) std::swap(arr[i], arr[j]);
		}
	}
}
int main(int argc, char* argv[])
{
	int n = atoi(argv[1]), * arr = new int[n];
	for (int i = 0; i < n; ++i)std::cin >> arr[i];

	BubbleSort(arr, n);

	for (int i = 0; i < n; ++i)std::cout << arr[i] << " ";
}