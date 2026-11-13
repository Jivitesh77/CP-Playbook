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
    while(t--){
        int n;
        cin >> n;
        map<long long, int> f;
        int count = 0;
        
        while (count != n) {
            long long tv;
            cin >> tv;
            f[tv] = f[tv] + 1;
            count++;
        }
        vll ans;
        ans.assign(n, 0);
        ll rt = 0;
        count = 0;
        bool possible = true; 
        for (;;) {
            if (count >= n) {
                break;
            }
            ll nf = 1;
            nf -= rt;
            map<long long, int>::iterator it = f.lower_bound(nf);
            if (it != f.end()) {
                ll picked = it->first;
                rt = rt + picked;
                ans[count] = rt;
                
                it->second = it->second - 1;
                if (!it->second) {
                    f.erase(it);
                }
            } else {
                cout << -1 << "\n";
                possible = false; 
                break; 
            }
            count++;
        }
        if (possible) {
            count = 0;
            do {
                if (n == 0) break;
                cout << ans[count];
                if (count != n - 1) {
                    cout << " ";
                }
                count++;
            } while (count < n);
            cout << "\n";
        }
    }

}