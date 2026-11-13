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
    ll n;
    cin >> n;
    vll a(10000);
    a[0] = n;
    int i=1;
    while(n != 1){
        if(n%2 == 0){
            n /= 2;
        }else{
            n = n*3 + 1;
        }
        a[i] = n;
            i++;
    }
    a.resize(i);
    for(int j = 0; j < sz(a); j++) {
        cout << a[j] << " ";
    }
    cout << '\n';



    
}
