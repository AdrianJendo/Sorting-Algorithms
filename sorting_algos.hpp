
#ifndef SORTING_ALGOS
#define SORTINGS_ALGOS

#include <vector>

using namespace std;

vector<int> insertionSort(const vector<int>& unsorted, const bool& ascending);
vector<int> selectSort(vector<int> unsorted, bool ascend); //pass by value
vector<int> mergeSort(const vector<int>& unsorted, const bool& ascending);
vector<int> quickSort(vector<int> unsorted, const bool& ascending); //pass by value

#endif