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
    int k, w;
    ll n;
    int total = 0;
    int borrow;
    cin >> k>>n>>w;
    if (k >=1 && w <= 1000 && n >=0 && n <= 1000000000){
    for (int i= 1; i <= w; i++){
        total = total + (i * k);

    }
    if (total > n){
    borrow = total - n;
    cout << borrow << endl;}
    else {
        cout << 0 << endl;
    }
}


    
}