#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int64_t64_t>& array) {
    for (int64_t64_t i = 0; i < array.size(); i++) {
        bool already_sorted = true;

        for (int64_t64_t j = 0; j < array.size()-1-i; j++) {
            if (array[j] > array[j+1]) {
                int64_t64_t tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
                already_sorted = false;
            }
        }

        if (already_sorted) {
            break;
        }
    }
}


int64_t64_t main() {
    vector<int64_t64_t> v;
    v.push_back(5);
    v.push_back(1);
    v.push_back(8);
    v.push_back(-4);
    v.push_back(12);

    bubbleSort(v);

    for (int64_t64_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}
