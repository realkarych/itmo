#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int64_t>& a) {
    for (int64_t i = 1; i < a.size(); i++) {
        int64_t j = i-1;
        int64_t key = a[i];
        while (j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

int main() {
    vector<int64_t> v;
    v.push_back(5);
    v.push_back(1);
    v.push_back(8);
    v.push_back(-4);
    v.push_back(12);

    insertionSort(v);

    for (int64_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}
