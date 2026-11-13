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
//     int x = 5000;
//     for (int i = 31; i >= 0; i--) {
// if (x&(1<<i)) cout << "1";
// else cout << "0";
// }
int x = 282;
for (int i = 0; i < 32; i++) {
if (x&(1<<i)) cout << i << " ";
}


    
}
