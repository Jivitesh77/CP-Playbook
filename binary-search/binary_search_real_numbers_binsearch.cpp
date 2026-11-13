#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// The array to store our ropes
vector<double> ropes;
int n, k;

// The checker function
bool good(double x) {
    long long pieces = 0;
    for (int i = 0; i < n; i++) {
        // How many pieces of length 'x' can we get from this rope?
        pieces += (long long)(ropes[i] / x);
    }
    // Can we get at least k pieces?
    return pieces >= k;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> k)) return 0;

    ropes.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> ropes[i];
    }

    double L = 0;
    double R = 1e8; // A safe upper bound based on problem constraints

    // 100 iterations is plenty for floating point binary search
    for (int i = 0; i < 100; i++) {
        double mid = L + (R - L) / 2;
        
        if (good(mid)) {
            // mid is possible, so try to find a LARGER length
            L = mid; 
        } else {
            // mid is impossible, so the answer must be SMALLER
            R = mid; 
        }
    }

    // Print the answer with 6 decimal places of precision
    cout << fixed << setprecision(6) << L << "\n";

    return 0;
}