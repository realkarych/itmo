#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int64_t partition(vector<int64_t>& arr, int64_t low, int64_t high) {
    int64_t middle = low + (high - low) / 2;
    int64_t l = arr[low];
    int64_t m = arr[middle];
    int64_t h = arr[high];

    int64_t median = max(min(l, m), min(max(l, m), h));

    if (median == l)
        swap(arr[low], arr[high]);
    else if (median == m)
        swap(arr[middle], arr[high]);

    int64_t pivot = arr[high];
    int64_t i = low - 1;
    int64_t j = high + 1;

    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}

void quickSort(vector<int64_t>& arr, int64_t low, int64_t high) {
    if (low < high) {
        int64_t pivot = partition(arr, low, high);

        quickSort(arr, low, pivot);
        quickSort(arr, pivot + 1, high);
    }
}

int main() {
    int64_t n;
    cin >> n;
    vector<int64_t> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);

    for (int64_t i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
