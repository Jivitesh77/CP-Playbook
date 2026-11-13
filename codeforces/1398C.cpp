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
        cin >> n;
        string s;
        cin >> s;

        map<ll, ll> freq;
        
        freq[0] = 1;

        ll p = 0; 
        for (int i = 1; i <= n; i++) {
            p += (s[i - 1] - '0'); 
            freq[p - i]++;         
        }

        ll ans = 0;
        for (auto& pair : freq) {
            ll x = pair.second;
            ans += x * (x - 1) / 2; 
        }

        cout << ans << endl;


    
}
}