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
    int a, b, c;
    
    if (t >=1 && t <= 10000){
        int gap =0;
        for (int i=0; i <t; i++){
            cin >> a >> b >> c;
            int gap = abs(a - b);
            int n = 2 * gap;
    if (a > n || b > n || c > n) {
        cout << -1 << "\n";
    } 
    else {
        if (c <= gap) {
            cout << c + gap << "\n";
        } else {
            cout << c - gap << "\n";
        }
    }
    }

    







    }
}