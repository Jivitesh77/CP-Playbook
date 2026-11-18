#include <algorithm>
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
    int n, k;
    cin >> k >> n;
    vll a(k);
    vll b(n);
    for(int i=0; i<k; i++){
        cin >> a[i];
    }
    for(int i =0; i<n; i++){
        cin >> b[i];
    }
    vll pref(k);
    pref[0] = a[0];
    for(int i =1; i <k; i++){
        pref[i] = pref[i-1] + a[i];

    }
    set<ll>cand;
    ll ans =0;

    for(int j=0; j <k; j++){
        cand.insert(b[0] - pref[j]);    
    }
        sort(all(pref));
        vll board(k);
            
        for (ll x : cand){
            bool ok = true;
            for(int j=0; j<k; j++){

            board[j] = (x + pref[j]);
        }
        for(int i=0; i<n; i++){
        if(!binary_search(all(board), b[i])){
            ok = false;
            break;
        }
    }
            if(ok){
            ans++;

        }
    }

    
    
    cout << ans;


}