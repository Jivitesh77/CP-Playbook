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
    vector<string> a(t);
    for (int i =0; i < t; i++){
        cin >> a[i];
        int zeroes = 0;

            for (int j = 0; j < a[i].size(); j++){
            if (a[i][j] == '0'){
                if (j == 0 || a[i][j - 1] == '1') {
                zeroes++;
            }
            }
        }
 if (zeroes == 0) {
        cout << 0 << "\n";
    } else if (zeroes == 1) {
        cout << 1 << "\n";
    } else {
        cout << 2 << "\n";
    }

        }
       
    }