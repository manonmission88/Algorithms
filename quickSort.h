#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include <algorithm>

using namespace std;

// Partition function to place pivot in correct position # passing num as a reference instead of the copy
int partition(vector<int> &nums, int low, int high) {  // Pass by reference
    int pivot = high; // last pivot index
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (nums[j] < pivot) {
            i++;
            swap(nums[i], nums[j]);
        }
    }

    swap(nums[i + 1], nums[high]); // pivot to its sorted correct position
    return i + 1;
}

// QuickSort function (Sorting in-place, so no return value)
void quickSort(vector<int> &nums, int low, int high) {  // Pass by reference
    if (low < high) {
        int partitionIndex = partition(nums, low, high);
        quickSort(nums, low, partitionIndex - 1);
        quickSort(nums, partitionIndex + 1, high);
    }
}

#endif // QUICKSORT_H
