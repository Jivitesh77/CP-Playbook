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
    int n;
  
    for(int i=0; i<t; i++){
          cin >> n;
    string s;
    cin >> s;
        int il = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            il++;
        }
    }
    int m = 0;
    
    for (int i = 1; i < n - 1; i++) {
        int ls = (s[i - 1] != s[i]) + (s[i] != s[i + 1]);
        int gs = (s[i - 1] != s[i + 1]);
        int drop = ls - gs;
        m = max(m, drop);
        if (m == 2) {
            break;
        }
    }

    cout << il - m << '\n';
    }

    
}
