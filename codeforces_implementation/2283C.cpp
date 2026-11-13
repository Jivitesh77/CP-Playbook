#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int k = 0;
    int M = 0;
    for (int i = 1; i <= n; i++) {
        k |= i;
        M ^= i;
    }

    vector<int> basis(20, 0);
    vector<vector<int>> basis_comp(20);
    vector<char> in_comp(n + 1, 0);
    vector<int> changed;

    // Build the linear basis for c_i = i ^ (2i)
    for (int i = 1; i <= n; ++i) {
        int val = i ^ (2 * i);
        int used = 0;
        
        for (int j = 19; j >= 0; --j) {
            if ((val >> j) & 1) {
                if (!basis[j]) {
                    basis[j] = val;
                    
                    // Track which original elements constitute this basis element 
                    auto flip = [&](int idx) {
                        if (!in_comp[idx]) changed.push_back(idx);
                        in_comp[idx] ^= 1;
                    };
                    
                    flip(i);
                    for (int bit = 19; bit >= 0; --bit) {
                        if ((used >> bit) & 1) {
                            for (int idx : basis_comp[bit]) {
                                flip(idx);
                            }
                        }
                    }
                    
                    // Store the active indices for this basis component
                    for (int idx : changed) {
                        if (in_comp[idx]) {
                            basis_comp[j].push_back(idx);
                            in_comp[idx] = 0; // reset for future iterations
                        }
                    }
                    changed.clear();
                    break;
                }
                val ^= basis[j];
                used ^= (1 << j);
            }
        }
    }

    // Function to check if a target XOR sum is reachable and print the configuration
    auto check = [&](int target) {
        int val = target;
        int used = 0;
        
        for (int j = 19; j >= 0; --j) {
            if ((val >> j) & 1) {
                if (!basis[j]) return false;
                val ^= basis[j];
                used ^= (1 << j);
            }
        }
        
        // If we can successfully form the target via our basis
        if (val == 0) {
            vector<int> ans(n + 1, 0);
            for (int bit = 19; bit >= 0; --bit) {
                if ((used >> bit) & 1) {
                    for (int idx : basis_comp[bit]) {
                        ans[idx] ^= 1;
                    }
                }
            }
            // Print out the bitwise mapping array
            for (int i = 1; i <= n; ++i) {
                cout << ans[i] << (i == n ? "" : " ");
            }
            cout << "\n";
            return true;
        }
        return false;
    };

    // The maximum possible valid 'm' generated can only be 2k or 2k + 1. 
    // The problem statement guarantees at least one will ALWAYS be achievable.
    if (!check((2 * k) ^ M)) {
        check((2 * k + 1) ^ M);
    }
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}