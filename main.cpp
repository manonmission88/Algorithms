#include <iostream>
#include <vector>
#include "quickSort.h"
using namespace std;
using namespace std::chrono;


// merge sort algorithms - using divide and conquer
vector<int> mergeArrays(vector<int> first, vector<int> second) {
    vector<int> final;
    int i = 0, j = 0;
    while (i < first.size() && j < second.size()) {
        if (first[i] < second[j]) {
            final.push_back(first[i]);
            i++;
        } else {
            final.push_back(second[j]);
            j++;
        }
    }

    while (i < first.size()) {
        final.push_back(first[i]);
        i++;
    }

    while (j < second.size()) {
        final.push_back(second[j]);
        j++;
    }

    return final;
}
// Implementing merge sort in C++
vector<int> mergeSort(vector<int> nums) {
    if (nums.size() <= 1) {
        return nums;
    }
    int mid = nums.size() / 2;

    vector<int> leftSort = mergeSort(vector<int>(nums.begin(), nums.begin() + mid));
    vector<int> rightSort = mergeSort(vector<int>(nums.begin() + mid, nums.end()));

    return mergeArrays(leftSort, rightSort); // Fixed function name conflict
}



int main() {
    vector<int> nums = {12, 11, 13, 5, 6, 7};
    cout << "Original array: ";
    for (int num : nums) cout << num << " ";
    cout << endl;
    auto start = high_resolution_clock::now();
    vector<int> sorted = mergeSort(nums);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Sorted array: ";
    for (int num : sorted) cout << num << " ";
    cout << endl;
    cout << "Time taken by merge sort: " << duration.count() << " microseconds" << endl;

    // for quick sort
    vector<int> nums1 = {10, 80, 30, 90, 40, 50, 70};

    cout << "Original array: ";
    for (int num : nums1) cout << num << " ";
    cout << endl;

    // Start time measurement
    auto start1 = high_resolution_clock::now();

    // Quick Sort
    quickSort(nums, 0, nums1.size() - 1);

    // End time measurement
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);

    cout << "Sorted array: ";
    for (int num : nums1) cout << num << " ";
    cout << endl;

    cout << "Time taken by Quick Sort: " << duration1.count() << " microseconds" << endl;
    return 0;
}
