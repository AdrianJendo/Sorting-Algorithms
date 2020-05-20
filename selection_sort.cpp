// Selection Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

void selectSort(vector<int>& unsorted, bool ascend) {
    int min = INT_MAX, indexMin = 0;
    int startIndex = (ascend ? 0 : unsorted.size() - 1);
    int counter = (ascend ? 1 : -1);
    int jMin = (ascend ? 0 : unsorted.size() + 1);

    for (unsigned int i = startIndex; i != unsorted.size()-startIndex-1; i+=counter) {
        min= INT_MAX;
        indexMin = startIndex;
        for (unsigned int j = i; j != unsorted.size()-jMin; j+=counter){
            if (unsorted[j] < min) 
                min = unsorted[j], indexMin = j;
         }
        if (indexMin != i) {
            unsorted[indexMin] = unsorted[i];
            unsorted[i] = min;
        }
    }
}

int main()
{
    vector<int> unsorted = { 5,6,7,3,112,2,1,12,14,444,100200,4,-1,3,17 };

    for (int i = 0; i < unsorted.size(); i++)
        cout << unsorted[i] << " ";

    cout << endl;
    selectSort(unsorted, false);

    for (int i = 0; i < unsorted.size(); i++)
        cout << unsorted[i] << " ";



    return 0;
}