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
    for(int i =0; i < t; i++){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int sc = 0;
        for(int j =0; j <n; j+=k){
            bool o = true;
            for(int l =0; l < k; l++){
                if(s[j + l] == '0'){
                    o = false;
                    break;
                }
            }
            if(o){
                sc++;
            } 
        }
        cout << sc << '\n';
    }


    
}