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
    int n;
    cin >> n;
    vll a(n);
    vll b(n);
    vll c(n);
    for(ll i=0; i<n; i++){
        cin >> a[i];
    }
    for(ll i=0; i<n; i++){
        cin >> b[i];
    }
    for(ll i =0; i <n; i++){
        cin >> c[i];
    }
    vll occ(n + 1, 0);
    for (ll x : a) {
        occ[x]++;
    }
    ll ans =0;
        for(ll cj : c){
            ans += occ[b[cj - 1]];
        }
        cout <<ans<<"\n";





    
}
