#include <iostream>
#include <vector>
#include <deque>

using namespace std;
vector<int> maxSlidingWindow(const vector<int>& arr, int k) {
    deque<int> dq; // Stores indices, not the actual values
    vector<int> result;

    for (int i = 0; i < arr.size(); i++) {
       
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

       
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }

       
        dq.push_back(i);

        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }
    
    return result;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Test Case: Standard LeetCode example
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    
    cout << "Original Array: ";
    for(int num : arr) {
        cout << num << " ";
    }
    cout << "\nWindow Size (K): " << k << "\n\n";

   
    vector<int> result = maxSlidingWindow(arr, k);

    cout << "Sliding Window Maximums: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}