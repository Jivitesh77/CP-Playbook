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
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int c1 = 0;
    int f1 = -1;
    int l1 = -1;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            c1++;
            if (f1 == -1) {
                f1 = i;
            }
            l1 = i;
        }
    }
    
    if (c1 == 1) {
        cout << 0 << "\n";
    } else if (c1 == 2) {
        cout << 1 << "\n";
    } else {
        cout << l1 - f1 << "\n";
    }    }
    
}