#include <vector>

using namespace std;

vector<int> selectSort(vector<int> unsorted, bool ascend) {
    if (unsorted.size()) {
        int min = INT_MAX, indexMin = 0;
        int startIndex = (ascend ? 0 : unsorted.size() - 1);
        int counter = (ascend ? 1 : -1);
        int jMin = (ascend ? 0 : unsorted.size() + 1);

        for (unsigned int i = startIndex; i != unsorted.size() - startIndex - 1; i += counter) {
            min = INT_MAX;
            indexMin = startIndex;
            for (unsigned int j = i; j != unsorted.size() - jMin; j += counter) {
                if (unsorted[j] < min)
                    min = unsorted[j], indexMin = j;
            }
            if (indexMin != i) {
                unsorted[indexMin] = unsorted[i];
                unsorted[i] = min;
            }
        }
    }
    return unsorted;
}