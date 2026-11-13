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
        do {
            int n;
            cin >> n;
            
            int mx = -1;
            int mn = 2e9 + 7; 
            while (n--) {
                int x;
                cin >> x;
                mn = (mn > x) ? x : mn;
                mx = (mx < x) ? x : mx;
            }
            
            int ans = mx;
            
            auto chk = [&](int k) {
                if (mx & (1 << k)) {
                    int pfx = (mx >> (k + 1)) << (k + 1);
                    int suf = (1 << k) - 1;
                    
                    int req = pfx + suf;
                    
                    if (mn <= req) {
                        int cnd = mx | suf;
                        ans = (ans > cnd) ? ans : cnd;
                    }
                }
            };

            int b = 30;
            while (b >= 0) {
                chk(b);
                b--;
            }
            
            cout << ans << endl;
            
        } while (--t > 0);
    }
    
}