#include <iostream>
#define SWAP(x, y, T) do{T t = x; x = y; y = t;} while(0)

/*
* SELECTION SORT
*	DISADVANTAGES:
*		1. Not Stable
*		2. Runtime O(n^2)
*		3. The amount of order already present in the list has no effect on runtime
*		( a sorted or almost sorted list will have about the same runtime as a non sorted one)
* 
*	ADVANTAGES:
*		1. In place (O(1) extra space reqd.)
*		2. Is the method of choice for sorting items with huge size and small keys
*		(	The swapping (movement of data) takes place in the outside the inner loop.
			For items with huge size and small keys, swapping them is of a much higher cost than simple comparison of keys.
			Selection sort's inner loop is mainly just performing a comparison of keys, so it is preferred in these cases.
		)
*/

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