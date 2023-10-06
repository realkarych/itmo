#include <iostream>
#include <vector>

using namespace std;

// Merge two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(vector<int64_t>& arr, int64_t left, int64_t mid, int64_t right) {
    int64_t n1 = mid - left + 1;
    int64_t n2 = right - mid;

    vector<int64_t> L(n1);
    vector<int64_t> R(n2);
    for (int64_t i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int64_t i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    // Merge the temporary arrays back int64_to arr[l..r]
    int64_t i = 0;
    int64_t j = 0;
    int64_t k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Main function to perform merge sort
void mergeSort(vector<int64_t>& arr, int64_t l, int64_t r) {
    if (l < r) {
        // Find the middle point64_t
        int64_t m = l + (r - l) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

int main() {
    vector<int64_t> arr = {12, 11, 13, 5, 6, 7};
    int64_t arrSize = arr.size();

    cout << "Original Array: ";
    for (int64_t i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, 0, arrSize - 1);

    cout << "Sorted Array: ";
    for (int64_t i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
