#include <iostream>
#include <vector>

/**
 * Binary Search Algorithm
 * 
 * Searches for a target value in a sorted array by repeatedly
 * dividing the search interval in half.
 * 
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 * 
 * @param arr    Sorted vector of integers (ascending order)
 * @param target Value to search for
 * @return       Index of target if found, -1 otherwise
 */
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;  // Prevents overflow
        
        if (arr[mid] == target) {
            return mid;  // Target found
        }
        else if (arr[mid] < target) {
            left = mid + 1;  // Search right half
        }
        else {
            right = mid - 1;  // Search left half
        }
    }
    
    return -1;  // Target not found
}

// ============== DEMONSTRATION ==============

int main() {
    // Must be sorted for binary search to work
    std::vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78};
    
    std::cout << "Array: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << "\n\n";
    
    // Test cases
    std::vector<int> targets = {23, 2, 78, 100};
    
    for (int target : targets) {
        int result = binarySearch(arr, target);
        
        std::cout << "Searching for " << target << ": ";
        if (result != -1) {
            std::cout << "Found at index " << result << "\n";
        } else {
            std::cout << "Not found\n";
        }
    }
    
    return 0;
}
