#include <vector>
#include "sorting_algos.hpp"

using namespace std;

vector<int> mergeSort(const vector<int>& unsorted, const bool& ascending) {
	unsigned int half = unsorted.size() / 2;
	vector<int> first_half(unsorted.begin(), unsorted.end() - half);
	vector<int> second_half(unsorted.end() - half, unsorted.end());

	if (first_half.size() && first_half.size() > 1)
		first_half = mergeSort(first_half, ascending); //sort the first half recusrively
	if (second_half.size() && second_half.size() > 1)
		second_half = mergeSort(second_half, ascending); //sort the second half recusrively

	vector<int> sorted;
	int i = 0, j = 0; //index pointers for both sublists
	while (i < first_half.size() && j < second_half.size()) {
		if ((first_half[i] >= second_half[j] && ascending) || (first_half[i] < second_half[j] && !ascending)) { //push back values into sorted as appropriate and increment pointers
			sorted.push_back(second_half[j]);
			++j;
		}
		else {
			sorted.push_back(first_half[i]);
			++i;
		}
	}

	if (i >= first_half.size()) //check if all elements from first half were already pushed in
		while (j < second_half.size()) { //add remaining elements from second half
			sorted.push_back(second_half[j]);
			++j;
		}
	else
		while (i < first_half.size()) { //add remaining elements from first half
			sorted.push_back(first_half[i]);
			++i;
		}
	return sorted;
}