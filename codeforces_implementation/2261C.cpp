#include <iostream>
#include <vector>

using namespace std;

void solve() {
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
    cin >> n >> m;
    
    if (n == 1) {
        cout << 0 << "\n";
    }else{
        vector<pair<int, int>> ans;
    
    if (n % 2 == 0) {
        ans.push_back({1, 2});
        int curr = 2;
        while (curr + 2 <= n - 2) {
            ans.push_back({curr, curr + 2});
            curr += 2;
        }
        if (n > 2) {
            ans.push_back({n - 2, n - 1});
        }
    } else {
        if (n == 3) {
            ans.push_back({1, 1});
            ans.push_back({1, 2});
        } else {
            ans.push_back({1, 1});
            ans.push_back({1, 3});
            int curr = 3;
            while (curr + 2 <= n - 2) {
                ans.push_back({curr, curr + 2});
                curr += 2;
            }
            ans.push_back({n - 2, n - 1});
        }
    }
    
    cout << ans.size() << "\n";
    for (auto& p : ans) {
        cout << p.first << " " << p.second << "\n";
    }
    }
    }
    
    
}