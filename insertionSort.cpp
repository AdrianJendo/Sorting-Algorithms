#include <vector>
#include "sorting_algos.hpp"

using namespace std;

vector<int> insertionSort(const vector<int>& unsorted, const bool& ascending) {
	vector<int> sorted;
	if (unsorted.size()) {
		sorted.push_back(unsorted[0]);
		for (int i = 1; i < unsorted.size(); ++i) {
			int j = 0;
			while (j < sorted.size() && (unsorted[i] > sorted[j] && ascending || unsorted[i] < sorted[j] && !ascending)) {
				++j;
			}
			sorted.insert(sorted.begin() + j, 1, unsorted[i]);
		}
	}
	return sorted;
}