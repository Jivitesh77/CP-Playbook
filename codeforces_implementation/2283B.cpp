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
            vi a(n);
            for (int &x : a) {
                cin >> x;
            }
            vi c(n, 0);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (a[i] % a[j] == 0) {
                        c[j]++;
                    }
                }
            }
            int b = *max_element(all(c));
            cout << n - b << endl;
        }
    }
}