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
    for(int i=0; i <t; i++){
       int n, m;
    cin >> n >> m;
    vector<int> freq(m + 2, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        freq[a]++;
    }
    vector<int> suf(m + 2, 0);
    for (int i = m; i >= 1; i--) {
        suf[i] = suf[i + 1] + freq[i];
    }    
    int mc = 0; 
    for (int v = 1; v <= m; v++) {
        int cc = suf[v];
        if (2 * v <= m) {
            cc += freq[2 * v];
        }
        
        mc = max(mc, cc);
    }
    
    cout << mc << '\n';


    }


    
}
