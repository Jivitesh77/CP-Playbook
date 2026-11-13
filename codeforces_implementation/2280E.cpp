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
        ll L;
        cin >> n >> L;
        vector<ll> a(n);
        for (auto &x : a){
            cin >> x;
        }
        sort(a.begin(), a.end());
        ll mx = a.back();
        a.pop_back(); 
        ll k = L - 1;
        ll lim = min(a.back(), (ll)sqrtl(k));
        if((lim + 1) * (lim + 1) <= k){
            lim++;
        }
        ll S = accumulate(a.begin(), a.end(), 0LL);
        ll ans = LLONG_MAX; 
        auto it = a.begin();
        for(ll v = 0; v <= lim; ++v){
            ll cur = S;
            if (v > 0){
                cur += max(0LL, mx - k / v);
            }
            ans = min(ans, cur);
            while(it != a.end() && *it <= v){
                ++it;
            }
            S -= distance(it, a.end()); 
        }
        cout << ans << '\n';
    }

    
}