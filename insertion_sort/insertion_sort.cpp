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

int main(int argc, char* argv[])
{
	int n = atoi(argv[1]), * arr = new int[n];
	for (int i = 0; i < n; ++i) std::cin >> arr[i];
	//InsertionSort1(arr, n);
	InsertionSort2(arr, n);
	for (int i = 0; i < n; ++i) std::cout << arr[i] << " ";
}
