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
        vll v(t, 0LL);
        for (int i = 0; i < t; ++i) {
            ll x, y;
            cin >> x >> y;
            if (x ^ y) {
                if ((x * y) > 0LL) {
                    v[i] = abs(x - y);
                } else {
                    ll d = abs(abs(x) - abs(y));
                    v[i] = max(0LL, d - 1LL);
                }
            }
        }   
        for (auto ans : v) {
            cout << ans << endl;
        }
    }
}