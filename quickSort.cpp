#include <vector>
#include "sorting_algos.hpp"

using namespace std;

/*
Quick Sort Implementation:
-choose middle element as pivot and swap with first
for ascending order (same algorithm for descending, but high and low are reversed):
-low starts at beginning and high starts at end
-move low pointer first
-swap with high pointer after cross
*/
//quick sort helper functions:
void swap(vector<int>& vctr, int index1, int index2) {
	if (index1 == index2 && index1 < vctr.size() && index2 < vctr.size())
		return;

	int temp = vctr[index1];
	vctr[index1] = vctr[index2];
	vctr[index2] = temp;
}

//start is (start index) of subsection and end is (end index + 1)
void quickSort(vector<int>& unsorted, int start, int end, const bool& ascending) {
	int size = end - start;
	if (size > 1) {
		int pivot = unsorted[(start + end) / 2]; //select pivot
		swap(unsorted, start, (start + end) / 2); //move pivot to front
		int i = start + 1; //select low (ascending) / high (descending)
		int j = end - 1; //select high (ascending) / low (descending)
		while (true) { //cross eventually happens, so we don't ever have to change this boolean
			if (ascending)
				while (i <= j && unsorted[i] <= pivot) //increment i
					++i;
			else
				while (i <= j && unsorted[i] >= pivot)
					++i;
			if (i <= j) { // no cross
				if (ascending)
					while (i <= j && unsorted[j] > pivot) //if no cross, decrement j
						--j;
				else
					while (i <= j && unsorted[j] < pivot)
						--j;
			}
			if (i > j) { //a cross happened
				swap(unsorted, start, j); //swap pivot with j
				if (j != 0)
					quickSort(unsorted, start, j, ascending); //recursive call to sort subcollections in 0(1) memory
				if (j + 1 != size)
					quickSort(unsorted, j + 1, end, ascending);
				return; //exit the function to not loop infinitely
			}
			else { //swap high and low if no cross 
				swap(unsorted, i, j);
			}
		}
	}
}

vector<int> quickSort(vector<int> unsorted, const bool& ascending) {
	quickSort(unsorted, 0, unsorted.size(), ascending);
	return unsorted;
}