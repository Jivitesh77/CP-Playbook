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
    int count[5] = {0};
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        count[x]++;
    }
    int cars = 0;
    cars += count[4];
    cars += count[3];
    count[1] -= min(count[1], count[3]);     
    cars += count[2] / 2;
    if (count[2] % 2 == 1) {
        cars++;
        count[1] -= min(count[1], 2);
    }
    if (count[1] > 0) {
        cars += (count[1] + 3) / 4;
    }
    cout << cars << "\n";
    
}
