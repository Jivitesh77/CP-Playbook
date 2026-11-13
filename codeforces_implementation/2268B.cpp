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
        int n, k;
        cin >> n >> k;
        vll a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        ll score = 0;
        int l = 0, r = n - 1;

        if (2 * k <= n) {
            for (int i = 0; i < k - 1; i++) {
                score += max(a[l], a[r]);
                l++;
                r--;
            }
            while (l <= r) {
                score += a[l];
                l++;
            }
        } else {
            int pairs = n - k + 1;
            for (int i = 0; i < pairs; i++) {
                score += max(a[l], a[r]);
                l++;
                r--;
            }
        }

        cout << score << endl;
    }
    return 0;
}