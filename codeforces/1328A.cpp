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
    ll a, b;
    ll add = 0;
    while (t--) {
        cin >> a >> b;
        if (a % b == 0) {
            cout << 0 << '\n';
        } else {
            cout << b - (a % b) << '\n';
        }
    }

    
}