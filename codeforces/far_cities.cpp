#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;

        int node1 = 1;
        int dist1 = 0;

        for (int i = 2; i <= n; ++i) {
            int d = dist1 + 1;
            while (d < n) {
                cout << "? 1 " << i << " " << d << "\n";
                cout.flush();
                
                int ans;
                cin >> ans;
                
                if (ans == -1) {
                    return 0;
                }
                
                if (ans == 1) {
                    node1 = i;
                    dist1++;
                    d++;
                } else {
                    break;
                }
            }
        }

        int node2 = 1; 
        int diameter = dist1;

        for (int i = 1; i <= n; ++i) {
            if (i == node1) continue;
            
            int cur = diameter + 1;
            while (cur < n) {
                cout << "? " << node1 << " " << i << " " << cur << "\n";
                cout.flush();
                
                int ans2;
                cin >> ans2;
                
                if (ans2 == -1) {
                    return 0;
                }
                
                if (ans2 == 1) {
                    node2 = i; 
                    diameter++;
                    cur++;
                } else {
                    break;
                }
            }
        }

        cout << "! " << node1 << " " << node2 << " " << diameter << "\n";
        cout.flush();
    }
}