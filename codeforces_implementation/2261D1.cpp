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
    if (cin >> t) {
        while (t--) {
            int n, m;
            cin >> n >> m; 
            if (n == 1) {
                cout << 0 << endl;
                continue;
            }
            int out_size = (n >> 1) + (n & 1);
            cout << out_size << endl;      
            bool is_odd = (n & 1);
            
            if (n == 2 || n == 3) {
                cout << 1 << " " << 1 << endl;
                if (n == 3) cout << 2 << " " << 2 << endl;
                continue;
            }
            
            if (is_odd) {
                cout<< 1 << " " << 1 << endl;
                cout<< 2 << " " << 3 << endl;
            } else {
                cout<< 1 << " " << 2 <<endl;
            }
            
            int p_start = is_odd ? 3 : 2;
            for (int v = p_start; v < n - 2; v += 2) {
                cout << v << " " << v + 2 << endl;
            }
            
            cout << n - 2 << " " << n - 1 << endl;
        }
    }

}