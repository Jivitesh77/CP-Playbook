#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...) 42
#endif

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) int((x).size())
#define pb push_back
#define eb emplace_back

constexpr int MOD = 998244353; // 1'000'000'007
constexpr ll INF = 4e18;
constexpr int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

template <class T, class U> T fstTrue(T lo, T hi, U f) {
    ++hi;
    while (lo < hi) {
        T mid = lo + (hi - lo) / 2;
        f(mid) ? hi = mid : lo = mid + 1;
    }
    return lo;
}

template <class T, class U> T lstTrue(T lo, T hi, U f) {
    --lo;
    while (lo < hi) {
        T mid = lo + (hi - lo + 1) / 2;
        f(mid) ? lo = mid : hi = mid - 1;
    }
    return lo;
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}