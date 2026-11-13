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
    string z = "";

    for (int i = 1; i <= n; i++) {
        if (i % 2 != 0) {
            z += "I hate";
        } else {
            z += "I love";
        }
        if (i == n) {
            z += " it";
        } else {
            z += " that ";
        }
    }

    cout << z << '\n';



    }