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
        vll a(n + 2, 0), d(n + 1, 0);
        for (int i = 1; i <= n; i++) cin >> a[i];
        ll top = 0;
        for (int i = 1; i < n; i++) {
            d[i] = abs(a[i] - a[i + 1]);
            if (d[i] > top) top = d[i];
        }
        auto eval = [&](ll m) {
            int id[3], c = 0;
            for (int i = 1; i < n; i++) {
                if (d[i] > m && c < 3) id[c++] = i;
            }
            if (c > 2) return false;
            if (!c) return true;
            auto valid = [&](int L, int R) {
                return (L < 2 || abs(a[L - 1] - a[R] * 2LL) <= m) & 
                       (R >= n || abs(a[L] * 2LL - a[R + 1]) <= m);
            };
            if (c == 2) {
                int iter = id[0] + 1;
                while (iter < id[1] && d[iter] * 2LL <= m) iter++;
                return (iter == id[1]) && valid(id[0] + 1, id[1]);
            }
            int pt = id[0];
            int R = pt + 1;
            while (R <= n) {
                if (valid(pt + 1, R)) return true;
                if (R < n && d[R] * 2LL > m) break;
                R++;
            }
            int L = pt;
            while (L >= 1) {
                if (valid(L, pt)) return true;
                if (L > 1 && d[L - 1] * 2LL > m) break;
                L--;
            }  
            return false;
        };
        ll cur = -1;
        for (ll jump = 1LL << 60; jump > 0; jump >>= 1) {
            ll attempt = cur + jump;
            if (attempt < top && !eval(attempt)) {
                cur = attempt;
            }
        }
        cout << cur + 1 << endl;
    }
}