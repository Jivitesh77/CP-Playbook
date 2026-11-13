#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define endl '\n'

const int MOD = 1e9 + 7;
const ll INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<vector<int>> a(n, vector<int>(3));
    int implement = 0; 
    if (n <= 1000 && n >= 1) {
        for (int i = 0; i < n; i++) {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
        }
        
        for (int i = 0; i < n; i++) {
            int implement_single = 0; 
            
            for (int j = 0; j < 3; j++) {
                if (a[i][j] == 1) {
                    implement_single++; 
                }
            }
            
            if (implement_single >= 2) {
                implement++;
            }
        }
    }
    
    cout << implement << endl;
    
}