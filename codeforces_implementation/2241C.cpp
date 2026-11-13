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
    
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        string s;
        int d = 0;
        cin >> s;
        for(int j=1; j <s.size(); j++){
            if(s[j] != s[j -1 ]){
                d++;
            }
        }
        if(d == 1){
            cout << 2<<"\n";
        }else{
            cout << 1 <<"\n";
        }
    }


    
}
