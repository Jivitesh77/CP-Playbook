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
        ll n, k;
        cin >> n >> k;
        vll a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        
        vll b(n + 1, 0);
        for(int i = 1; i <= n; i++){
            b[i] = b[i - 1] + a[i - 1];
        }
        
        map<int, int> f;
        ll ans = 0;
        for(int i = k + 1; i <= n; i++){
            f[b[i - (k + 1)] % k]++;
            ans += f[b[i] % k];
        }
        cout << ans << endl;
    }
}