#include <iostream>

/*
QUICKSORT
Quick sort is a divide and conquer algorithm.
It takes a pivot element at some index i, and ensures that 
arr[i] reaches its final position in the sorted array each time the partition procedure is called.
All elements to the left of pivot (index < i) are lesser than arr[i], and all to the right are greater.a

Now the array is subdivided from this pivot element, and quicksort is recursively called on the subparts.

PROPERTIES:

1. In-place (no extra space is required, except a small auxilliary stack for recursive implementation)
2. Not stable
3. Runtime: O(N log N) in the average case, O(N^2) in the worst case. Runtime is dependent on the order of input too.
*/


int partition(int* arr, int l, int r)
{
	int v = arr[r];  // take rightmost as pivot
	int i = l - 1, j = r;

	while (true)
	{
		while (arr[++i] < v); // scan from left, stop at first element >= v

		// scan from right, stop at first element <= v
		while (arr[--j] > v) 
			if (j <= l) break;
		
		if (i >= j) break; // pointers have crossed.
		std::swap(arr[i], arr[j]); // swap elements at i and j because they are obviously out of place.
	}
	std::swap(arr[i], arr[r]); // put pivot into position
	return i;
}
void QuickSort(int* arr, int l, int r)
{
	if (l >= r) return;
	int i = partition(arr, l, r);
	QuickSort(arr, l, i-1);
	QuickSort(arr, i+1, r);
}
void main(int argc, char* argv[])
{
	int n = atoi(argv[1]), k = atoi(argv[2]), * arr = new int[n];
	for (int i = 0; i < n; ++i) arr[i] = rand() % k;

	std::cout << "Unsorted array: ";
	for (int i = 0; i < n; ++i) std::cout<<arr[i]<<" ";
	std::cout << "\n";
	
	QuickSort(arr, 0, n - 1);

	std::cout << "Sorted array: ";
	for (int i = 0; i < n; ++i) std::cout<<arr[i]<<" ";
	std::cout << "\n";

}