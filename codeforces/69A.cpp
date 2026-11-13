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
    int sumx = 0;
    int sumy = 0;
    int sumz = 0;
    for(int i=0; i<n; i++){
        int a, b, c;
        cin >> a >> b >>c;
        sumx += a;
        sumy += b;
        sumz += c;
    }
    if(sumx == 0 && sumy == 0 && sumz == 0){
         cout << "YES\n";
    }else{
        cout << "NO\n";
    }


    
}
