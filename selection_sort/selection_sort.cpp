#include <iostream>
#define SWAP(x, y, T) do{T t = x; x = y; y = t;} while(0)

void SelectionSort(int* arr, int n)
{
	if (n == 0 || n == 1) return;

	int max_idx;
	for (int j = n - 1; j > 1; --j)
	{
		max_idx = 0;
		for (int i = 1; i < j; ++i)
		{
			if (arr[i] > arr[max_idx]) max_idx = i;
		}
		std::swap(arr[max_idx], arr[j]);
	}
}
int main(int argc, char* argv[])
{
	int n = atoi(argv[1]);
	int* arr = new int[n];
	for (int i = 0; i < n; ++i) std::cin >> arr[i];
	SelectionSort(arr, n);
	for (int i = 0; i < n; ++i) std::cout << arr[i] << " ";

	return 0;
}