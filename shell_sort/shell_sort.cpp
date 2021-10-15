#include <iostream>

/*
SHELL SORT

Shell sort presents a solution to counter the inefficiency which insertion sort faces
due to it only moving elements by one place each time.

Shell sort uses an h-sorted file: file (array) in which every h-th element (starting anywhere) is in order.
So using any increment sequence, which ends with h=1 (normal insertion sort), results in a fully sorted file.

1. Not Stable
2. In-place
3. Adaptive (when using adaptive insertion sort)
4. Can be made better by using a better increment sequence.
*/


void ShellSort(int* arr, int n)
{
	// h-sorted file
	// Knuth's increment sequence: 1, 4, 13, 40... (basically h next = h*3 + 1)

	int h;
	for (h = 1; h <= n / 9; h = (h * 3) + 1);

	// insertion sort
	for (; h >= 1; h /= 3)
	{
		for (int i = h; i < n; i++)
		{
			for (int j = i; j > 0; j -= h)
			{
				if (arr[j] < arr[j - h]) std::swap(arr[j], arr[j - h]);
				else break;
			}
		}
	}
}

int main(int argc, char* argv[])
{
	int n = atoi(argv[1]), * arr = new int[n];
	for (int i = 0; i < n; ++i) std::cin >> arr[i];
	ShellSort(arr, n);
	for (int i = 0; i < n; ++i) std::cout << arr[i] << " ";
}