#include <iostream>

void merge1(int* arr, int l, int m, int r)
{
	// linear time merging procedure. filling from r to l.

	int* aux = new int[r - l + 1];
	for (int i = m, j = r, k = r - l; k >= 0; k--)
	{

		if (i < l) { aux[k] = arr[j--]; continue; }
		else if (j < m + 1){ aux[k] = arr[i--]; continue; }
		aux[k] = (arr[i] > arr[j] ? arr[i--] : arr[j--]);
	}
	for (int i = l; i <= r; ++i) arr[i] = aux[i - l];
}

void merge2(int* arr, int l, int m, int r)
{
	// linear time merging procedure. filling from l to r.
	
	int* aux = new int[r - l + 1];

	for (int i = l, j = m + 1, k = 0; k <= r - l; k++)
	{
		if (i > m) { aux[k] = arr[j++]; continue; }
		else if (j > r) { aux[k] = arr[i++]; continue; }
		aux[k] = (arr[i] < arr[j] ? arr[i++] : arr[j++]);
	}
	
	for (int i = l; i <= r; ++i) arr[i] = aux[i - l];
}

void MergeSort(int* arr, int l, int r)
{
	if (l >= r) return;
	int m = (l + r) / 2;
	MergeSort(arr, l, m);
	MergeSort(arr, m+1, r);
	merge1(arr, l, m, r);
}

int main(int argc, char* argv[])
{
	int n = atoi(argv[1]), * arr = new int[n];
	for (int i = 0; i < n; ++i)std::cin >> arr[i];
	MergeSort(arr, 0, n - 1);
	for (int i = 0; i < n; ++i)std::cout << arr[i] << " ";
}

/*
MERGE SORT
It is a classic divide and conquer algorithm.

An array comprising of a single element is always sorted.
Merge sort starts by recursively diving the larger array into smaller and smaller subarrays,
until only single element arrays are left.

Then the Merge procedure is called on sets of two subarrays, which merges these (sorted) subarrays,
such that the combined (merged) subarray is also sorted.

PROPERTIES:
1. STABLE (Unlike quicksort and heapsort)
2. NOT ADAPTIVE (Runtime just depends on the size N, not on the order already present)
3. NOT IN-PLACE (Extra space proportional to N is required for linear merging procedure)

4. RUNTIME: O(N log N) in every case.
	This may be better than quicksort whose runtime can be O(N^2) in the worst case,
	but it also uses extra O(N) space which may be undesirable.

	Heapsort is a better alternative if a guaranteed O(N log N) time is required as it is in-place.
	Mergesort is a better alternative only when stability is necessary.

	Due to it being non-adaptive, even algorithms such as insertion and bubble sort may give a better runtime (O(N)),
	if some order is present, or, one might want to consider going with linear time sorting algorithms such as count and
	radix sort.

5. MERGING PROCEDURE IS USUALLY IMPLEMENTED AS SEQUENTIAL:
	This is especially beneficial when we are sorting linked-lists, or other data structs where only sequential access
	is available.

6. MERGING HAS OTHER REAL LIFE APPLICATIONS:
	Example: If we have to maintain a large sorted file, to which we need to add batches of new data from time to time,
	we would want to sort the small new batch and then merge it with the larger sorted file.
*/