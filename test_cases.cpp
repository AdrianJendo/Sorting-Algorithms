
#include <iostream>
#include <vector>
#include <chrono>
#include "sorting_algos.hpp"

using namespace std;

void print(const vector<int>& vctr) {
	for (int i = 0; i < vctr.size(); ++i)
		cout << "[" << vctr[i] << "] ";
	cout << endl;
}

int main() {
	vector<int> unsorted;
	srand(1); //random seed
	for (int i = 0; i < 25; ++i) //size = 25
		unsorted.push_back(int(double(rand()) / RAND_MAX * (100 - (-100) + 1)) + (-100)); //random int between -100 and 100
		//unsorted.push_back(i);

	cout << "Unsorted: " << endl;
	print(unsorted);
	cout << endl;

	//Insertion Sort:
	cout << "Insertion Sort in ascending order:" << endl;
	auto start_time = chrono::steady_clock::now();
	vector<int> insertion_ascending = insertionSort(unsorted, true);
	auto end_time = chrono::steady_clock::now();
	print(insertion_ascending);
	cout << chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " microseconds" << endl;

	cout << "Insertion Sort in descending order:" << endl;
	start_time = chrono::steady_clock::now();
	vector<int> insertion_descending = insertionSort(unsorted, false);
	end_time = chrono::steady_clock::now();
	print(insertion_descending);
	cout << chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " microseconds" << endl;
	cout << endl;

	//Merge Sort:
	cout << "Merge Sort in ascending order:" << endl;
	start_time = chrono::steady_clock::now();
	vector<int> merge_ascending = mergeSort(unsorted, true);
	end_time = chrono::steady_clock::now();
	print(merge_ascending);
	cout << chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " microseconds" << endl;

	cout << "Merge Sort in descending order:" << endl;
	start_time = chrono::steady_clock::now();
	vector<int> merge_descending = mergeSort(unsorted, false);
	end_time = chrono::steady_clock::now();
	print(merge_descending);
	cout << chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " microseconds" << endl;
	cout << endl;

	//Quick Sort:
	cout << "Quick Sort in ascending order:" << endl;
	start_time = chrono::steady_clock::now();
	vector<int> quick_ascending = quickSort(unsorted, true);
	end_time = chrono::steady_clock::now();
	print(quick_ascending);
	cout << chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " microseconds" << endl;

	cout << "Quick Sort in descending order:" << endl;
	start_time = chrono::steady_clock::now();
	vector<int> quick_descending = quickSort(unsorted, false);
	end_time = chrono::steady_clock::now();
	print(quick_descending);
	cout << chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " microseconds" << endl;
	cout << endl;

	//Selection Sort:
	cout << "Selection Sort in ascending order:" << endl;
	start_time = chrono::steady_clock::now();
	vector<int> selection_ascending = selectSort(unsorted, true);
	end_time = chrono::steady_clock::now();
	print(selection_ascending);
	cout << chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " microseconds" << endl;

	cout << "Selection Sort in descending order:" << endl;
	start_time = chrono::steady_clock::now();
	vector<int> selection_descending = selectSort(unsorted, false);
	end_time = chrono::steady_clock::now();
	print(selection_descending);
	cout << chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " microseconds" << endl;
	cout << endl;

	//Other test cases
	vector<int> unsorted2(1000, 1); //100 numbers, all the same
	vector<int> unsorted3 = { 1 }; //1 element
	vector<int> unsorted4; //0 elements
	vector<int> unsorted5 = { 2, 1 }; //2 elements
	vector<int> unsorted6 = { 3,1,2 }; //3 elements
	vector<int> unsorted7 = { 1,2,3,4,5 }; //ascending order
	vector<int> unsorted8 = { 5,4,3,2,1 }; //descending order
}