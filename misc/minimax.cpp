#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Checks if it's possible for everyone to meet within time t
bool check(double t, const vector<double>& x, const vector<double>& v) {
    double max_left = -1e18; // Represents negative infinity
    double min_right = 1e18; // Represents positive infinity
    
    for (size_t i = 0; i < x.size(); ++i) {
        // Calculate the reachable segment for person i in time t
        double left_bound = x[i] - t * v[i];
        double right_bound = x[i] + t * v[i];
        
        // Update the intersection boundaries
        max_left = max(max_left, left_bound);
        min_right = min(min_right, right_bound);
    }
    
    // If the highest left boundary is <= the lowest right boundary, they overlap
    return max_left <= min_right;
}

// Binary searches for the minimum possible meeting time
double find_minimax_time(const vector<double>& x, const vector<double>& v) {
    double left = 0.0;
    double right = 1e9; // A sufficiently large upper bound (adjust based on problem constraints)
    
    // 100 iterations guarantee extremely high precision for floating-point answers
    for (int i = 0; i < 100; ++i) {
        double mid = left + (right - left) / 2.0;
        
        if (check(mid, x, v)) {
            // If time 'mid' works, try to find a smaller (better) time
            right = mid;
        } else {
            // If it doesn't work, we need more time
            left = mid;
        }
    }
    
    return right;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Example Usage
    vector<double> positions = {1, 5, 10};
    vector<double> speeds = {2, 1, 3};
    
    double min_time = find_minimax_time(positions, speeds);
    
    // Print with 6 decimal places of precision
    cout << fixed << setprecision(6);
    cout << "Minimum time for all to gather: " << min_time << "\n";
    
    return 0;
}