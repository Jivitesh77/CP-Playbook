#include <iostream>
#include <vector>

int findClosestLeft(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int closestLeftIndex = -1; 
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] <= target) {
            closestLeftIndex = mid;
            left = mid + 1;
        } else {
            // arr[mid] is too big. We must look on the left.
            right = mid - 1;
        }
    }
    
    return closestLeftIndex;
}

// Closest Right (Ceiling): Smallest element >= target
int findClosestRight(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int closestRightIndex = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] >= target) {
            // arr[mid] is valid. Record it, and try to find a closer (smaller) one on the left.
            closestRightIndex = mid;
            right = mid - 1;
        } else {
            // arr[mid] is too small. We must look on the right.
            left = mid + 1;
        }
    }
    
    return closestRightIndex;
}

int main() {
    std::vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target = 15;

    int leftIndex = findClosestLeft(arr, target);
    int rightIndex = findClosestRight(arr, target);

    std::cout << "Array: [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]\n";
    std::cout << "Target: " << target << "\n\n";

    if (leftIndex != -1) {
        std::cout << "Closest Left (Floor): " << arr[leftIndex] << " at index " << leftIndex << "\n";
    } else {
        std::cout << "Closest Left (Floor): None found\n";
    }

    if (rightIndex != -1) {
        std::cout << "Closest Right (Ceiling): " << arr[rightIndex] << " at index " << rightIndex << "\n";
    } else {
        std::cout << "Closest Right (Ceiling): None found\n";
    }

    return 0;
}