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
        int n;
        ll c;
        cin >> n >> c;
        vector<ll> a(n);
        
        for(int j = 0; j < n; j++){
            cin >> a[j];
        }
        sort(a.rbegin(), a.rend());
        
        ll s = 0;
        ll m = -INF;
        for(int k = 1; k <= n; k++){
            s += a[k - 1];
            if(k >= (n + 1) / 2){
                ll sc = s - (k * c);
                m = max(m, sc);
            }
        }
        
        cout << m << endl;
    }
    
    return 0;
}