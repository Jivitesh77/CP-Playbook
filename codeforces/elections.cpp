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
        for (int i=0; i < t; i++){
            cin >> a >> b >> c;
            

            int a_win = max(0, max(b, c) + 1 - a);
            int b_win = max(0, max(a, c) + 1 - b);
            int c_win = max(0, max(a, b) + 1 - c);

cout << a_win << " " << b_win << " " << c_win << "\n";

        }
    

    }



    
}