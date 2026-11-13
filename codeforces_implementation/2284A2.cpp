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
    while(t--) {
            int n;
            cin >> n;
            priority_queue<ll> pq;
            int i = n;
            while (i > 0) {
                ll x;
                cin >> x;
                pq.push(1LL << x);
                i -= 1;
            }
            ll s[2] = {0LL, 0LL};
            
            while (!pq.empty()) {
                ll u = pq.top();
                pq.pop();
                s[s[0] > s[1]] += u;
            }
            ll ans = s[0] * s[1];
            cout << ans << (char)10;
        }
    }
