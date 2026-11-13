#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to find the nearest smaller element to the left
vector<int> nearestSmallerLeft(const vector<int>& arr) {
    vector<int> result(arr.size(), -1); // Initialize all with -1
    stack<int> st;

    for (int i = 0; i < arr.size(); i++) {
        // 1. Pop elements from the stack that are greater than or equal to current element
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }
        
        // 2. If stack is not empty, the top element is the nearest smaller element
        if (!st.empty()) {
            result[i] = st.top();
        }
        
        // 3. Push the current element onto the stack for future elements to compare against
        st.push(arr[i]);
    }
    
    return result;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Test Case: Standard mixed array
    vector<int> arr = {4, 5, 2, 10, 8};
    
    cout << "Original Array:  ";
    for(int num : arr) {
        cout << num << " ";
    }
    cout << "\n";

    // Run the algorithm
    // Run the algorithm
    vector<int> result = nearestSmallerLeft(arr);

    cout << "Nearest Smaller: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}