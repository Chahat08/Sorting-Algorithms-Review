#include <iostream>
#define M 5

/*
COUNTING SORT
Non comparison based sorting algorithm

Properties:
1. Stable
2. Not in-place
3. Runtime: O(n)
4. Auxilliary space: O(n+M) ( needs seperate input and output arrays, plus the cnt array)
*/


// key-indexed counting sort
int* CountSort(int* arr, int n)
{
	int cnt[M] = {};
	int* sorted = new int[n];

	// cnt will now store the no. of occurences of each number
	for (int i = 0; i < n; ++i)
		cnt[arr[i]]++;

	// added every element of cnt to the one before it
	// now cnt contains the indices before which each cnt index ends in sorted array.
	for (int i = 1; i < M; ++i)
		cnt[i] = cnt[i - 1] + cnt[i];

	// shifting cnt to the right by one
	// cnt now contains the starting indices in sorted array for each index.
	for (int i = M-1; i > 0; --i)
		cnt[i] = cnt[i - 1];
	cnt[0] = 0;

	// iterate through the array
	// look at where to put that element in the sorted array by looking at its index in cnt
	// increment cnt at that position because the next occurance of that element will come 
	for (int i = 0; i < n; ++i)
		sorted[cnt[arr[i]]++] = arr[i];

	return sorted;

}
int main(int argc, char* argv[])
{
	int n = atoi(argv[1]), * arr = new int[n];

	for (int i = 0; i < n; ++i) { arr[i] = rand() % M; }
	for (int i = 0; i < n; ++i) std::cout << arr[i] << " ";
	// vals in arr range from 0 to M-1 (0 to 4)

	int* s = CountSort(arr, n);
	std::cout << "\n";
	for (int i = 0; i < n; ++i) std::cout << s[i] << " ";
	std::cout << "\n";

	return 0;
}