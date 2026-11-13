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
    if (cin >> t) {
        while (t--) {
            int n;
            cin >> n;
            int xx = 0;
            for (int i = n; i > 0; --i) {
                xx ^= i;
            }
            int l = __lg(n) + 1;         
            int tg = (2 << l) - 2;
            int z = xx ^ tg;
            if (__builtin_parity(z)) {
                z ^= 1;  
            }
            vi ans(n + 1, 0);
            int p = 0;
            
            for (int step = 0, pwr = 1; step < l; ++step, pwr <<= 1) {
                int b = ((z >> step) & 1) ^ p;   
                if (b) {
                    ans[pwr] = 1;
                }
                p = b;
            }
            for (int i = 1; i <= n; ++i) {
                cout << ans[i] << " \n"[i == n];
            }
        }
    }
}