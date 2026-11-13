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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
    cin >> n >> x;
    vi a(n);
    for (int j = 0; j < n; j++) {
        cin >> a[j];
    }
    vi primes;
    int temp = x;
    for (int d = 2; d * d <= temp; d++) {
        if (temp % d == 0) {
            primes.pb(d);
            while (temp % d == 0) {
                temp /= d;
            }
        }
    }
    if (temp > 1) {
        primes.pb(temp);
    }
    ll max_loot = 0;
    for (int p : primes) {
        ll current_loot = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] % p == 0) {
                current_loot += a[j];
            }
        }
        max_loot = max(max_loot, current_loot);
    }

    cout << max_loot << endl;

    }
}