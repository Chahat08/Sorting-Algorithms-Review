#include <iostream>


// key-indexed counting sort
void CountSort(int* arr, int n)
{

}
int main(int argc, char* argv[])
{
	int n = atoi(argv[1]), * arr = new int[n];
	for (int i = 0; i < n; ++i) std::cin >> arr[i];
	CountSort(arr, n);
	for (int i = 0; i < n; ++i) std::cout << arr[i] << " ";
}