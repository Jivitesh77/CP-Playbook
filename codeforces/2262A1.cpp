#include <bits/stdc++.h>
using namespace std;

#define int long long

const int md = 1e9 + 7;
const int nmax = 200005;

int f[nmax];

void prec() {
    *f = 1;
    int i = 0;
    while (++i < nmax) {
        *(f + i) = (*(f + i - 1) * i) % md;
    }
}

bool chk(int d, int* a, int n, int m) {
    if (0 >= d) return 0;
    
    vector<int> g(n);
    int k = 0, p = 0;
    do {
        *(g.data() + p++) = k * d;
        *(g.data() + p++) = *(a + n - 1) - k * d;
    } while (++k < m);
    
    sort(g.begin(), g.end());
    
    int i = n;
    while (i--) {
        if (*(g.data() + i) ^ *(a + i)) return 0;
    }
    return 1;
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<int> a(n);
    int j = 0;
    while (n > j) cin >> *(a.data() + j++);

    if (n & 1) {
        int m = n >> 1;
        int ans = 0;
        int lst = *(a.data() + n - 1);
        if (lst == (lst / (n - 1)) * (n - 1)) {
            if (int d = lst / (n - 1); d >= 0) {
                int i = n, ok = 1;
                while (i--) {
                    if (*(a.data() + i) ^ (i * d)) {
                        ok = 0;
                        break;
                    }
                }
                if (ok) ans = (*(f + m) * *(f + m - 1)) % md;
            }
        }
        cout << ans << "\n";
    } else {
        int m = n >> 1;
        int ans = 0;
        int c1 = *(a.data() + 1);
        int c2 = -1;
        
        if (int df = *(a.data() + n - 1) - c1; df == (df / (m - 1)) * (m - 1)) {
            c2 = df / (m - 1);
        }

        if (chk(c1, a.data(), n, m)) {
            ans = (ans + (*(f + m) * *(f + m - 2)) % md) % md;
        }
        
        if (c2 > 0) {
            if (c1 ^ c2) {
                if (chk(c2, a.data(), n, m)) {
                    ans = (ans + (*(f + m) * *(f + m - 2)) % md) % md;
                }
            }
        }
        cout << ans << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    prec();
    
    int t;
    if (cin >> t) {
        while (t--) solve();
    }
}