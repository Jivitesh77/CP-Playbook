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
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int c[2] = {0, 0};
        int m = n * 2;   
        for (int i = 0; i < m; ++i) {
            int v;
            cin >> v;
            if (!((v ^ k) & 1)) {
                c[i >= n]++;
            }
        }
        if (c[0] > c[1]) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}