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
    while(t--){
        int n, k;
        cin >> n >> k;
        deque<ll> dq;
        int i = 0;
        while (i < n) {
            ll val;
            cin >> val;
            dq.pb(val);
            i++;
        }
        sort(all(dq));
        ll mx = dq.back();
        int c = 0;
        int ptr = n - 1;
        while (ptr >= 0 && dq[ptr] == mx) {
            c++;
            ptr--;
        }
        if (k < c) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        vi o;
        o.pb(n - 1);
        int rev = n - k - 1;
        while (rev >= 0) {
            o.pb(rev);
            rev--;
        }
        int fwd = n - k;
        while (fwd < n - 1) {
            o.pb(fwd);
            fwd++;
        }
        for (int pos : o) {
            cout << dq[pos] << " ";
        }
        cout << "\n";
    }
}