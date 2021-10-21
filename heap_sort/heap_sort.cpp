#include <iostream>
#include <vector>

using namespace std;

/*
HEAP SORT
In heap sort, we first create a max heap from all the nodes.
Then we take the root (max key element) out of the max heap and swap it with the last element.
( Such that the last element becomes the max element )

Then we Insert the first element into its place in the remaining heap.

Do this till only one element remains in the heap.

Kinda like selection sort in that the current largest element is sorted each iteration.
( sorted and unsorted portions are maintained in both )
*/

void build_max_heap(vector<int>& v)
{
	for (int idx = 0; idx < v.size(); ++idx)
	{
		for (int i = idx, j = (i - 1) / 2; j >= 0; i = j, j = (i - 1) / 2)
		{
			if (v[i] <= v[j]) break;
			swap(v[i], v[j]);
		}
	}
}

void heap_sort(vector<int>& v)
{
	build_max_heap(v);
	// create a max heap, so the first element is the largest

	for (int j = v.size() - 1; j > 0 ; ) // j is the end of the sorted portion
	{
		// swap the first element with the last, now last = largest
		swap(v[0], v[j--]);

		// now insert the element which was swapped with largest (curr idx = 0) into the heap
		for (int i = 0; 2 * i + 1 < j;)
		{
			if (v[i] >= v[2 * i + 1] && v[i] >= v[2 * i + 2]) break;

			else if (v[2 * i + 1] >= v[2 * i + 2])
			{
				std::swap(v[i], v[2 * i + 1]);
				i = 2 * i + 1;
			}
			else
			{
				std::swap(v[i], v[2 * i + 2]);
				i = 2 * i + 2;
			}
		}
	}
}

int main()
{
	vector<int> v({ 1,8,5,3,2,9 });
	heap_sort(v);

	for (int& i : v) cout << i << " ";
	cout << endl;

	return 0;
}