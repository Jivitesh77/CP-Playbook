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
int w, h, n; 
bool good(int x){
    return (x/w) * (x/h) >=n;
}

const int MOD = 1e9 + 7;
const ll INF = 1e18;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> w>>h>>n;
    int l =0;
    int r = 1;
    while(!good(r)) r *=2;

    

    while(r > l+1){
        int m = (l+r)/2;
        if (good(m)){
            r = m;
        }else{
            l = m;
        }
    }
    cout << r;
    return 0;


    
}