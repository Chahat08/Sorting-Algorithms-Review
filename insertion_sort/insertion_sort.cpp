#include <iostream>

/*
* BASIC INSERTION SORT
* Take a given element and insert it into its position in the sorted array.
*/

void InsertionSort1(int* arr, int n)
{
	for (int i = 1; i < n; ++i)
		for (int j = i; j > 0; --j)
			if (arr[j] < arr[j - 1])
				std::swap(arr[j], arr[j - 1]);
}

/*
* IMPROVEMENTS OVER BASIC ALGORITHM
*  1. Once the element under consideration is put into its position in the sorted portion, 
*     there is no need to continue, so break
*	
*	The above improvement makes the sort ADAPTIVE, since it appropriately adapts to certain order in the array.
*/
void InsertionSort2(int* arr, int n)
{
	for (int i = 1; i < n; ++i)
		for (int j = i; j > 0; --j)
		{
			if (arr[j] < arr[j - 1])
				std::swap(arr[j], arr[j - 1]);
			else break;
		}
}
/*
* FURTHER IMPROVEMENTS
*  2. The condition j > 0 is checked in every iteration of the inner loop, but it actually matters only when the
*	  element under consideration is the smallest element so far. (since we are now early breaking)
*     
*	  To get rid of this statement, use a SENTINEL. Simply insert an INT_MIN to front, or better,
*	  just make a single pass and find the smallest element and swap it with the first element.	
* 
*	Not a major improvement since we are still making a pass through the entire array, while doing comparisons.
*/
void InsertionSort3(int* arr, int n)
{
	int min = 0;
	for (int i = 1; i < n; ++i) if (arr[i] < arr[min]) min = i;
	std::swap(arr[0], arr[min]);

	for (int i = 1; i < n; ++i)
		for (int j = i; ; --j)
		{
			if (arr[j] < arr[j - 1])
				std::swap(arr[j], arr[j - 1]);
			else break;
		}
}
/*
* EVEN FURTHER IMPROVEMENTS
*  3. Swapping can be somewhat inefficient, especially when done successively, 
*	  so we can modify our code to avoid it altogether.
*/
void InsertionSort4(int* arr, int n)
{
	int min = 0, v;
	for (int i = 1; i < n; ++i) if (arr[i] < arr[min]) min = i;
	std::swap(arr[0], arr[min]);

	for (int i = 1, j; i < n; ++i)
	{
		v = arr[i];
		for (j = i; ; --j)
		{
			if (v < arr[j - 1])
				arr[j] = arr[j - 1];
			else
				break;
		}
		arr[j] = v;
	}
}

int main(int argc, char* argv[])
{
	int n = atoi(argv[1]), * arr = new int[n];
	for (int i = 0; i < n; ++i) std::cin >> arr[i];
	//InsertionSort1(arr, n);
	//InsertionSort2(arr, n);
	//InsertionSort3(arr, n);
	InsertionSort4(arr, n);
	for (int i = 0; i < n; ++i) std::cout << arr[i] << " ";
}
