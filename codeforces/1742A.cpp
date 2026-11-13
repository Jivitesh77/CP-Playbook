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
    for(int i=0; i <t; i++){
        vector<int> v(3, 0);
        cin >> v[0] >> v[1] >> v[2];
        sort(all(v));
        if(v[2] == (v[0] + v[1])){
            cout << "YES" << "\n";
        }else{
            cout<<"NO" << "\n";
        }
        
    }



    
}