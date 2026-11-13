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
    for(int i =0; i<t; i++){
        int n;
        cin >> n;
        int o = 0;
        int m0 = 0;
        int m2 = 0;
        for(int j =0; j < n; j++){
            int x;
            cin >> x;
            if(x % 2 != 0){
                o++;
            }else if(x % 4 == 0){
                m0++;

            }else{
                m2++;
            }
        }
        cout << max({m0, m2, o}) << "\n";
    }


    
}