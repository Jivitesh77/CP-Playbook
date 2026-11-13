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
    vll a(n);
    ll moves = 0;
    for(int i =0; i<n;i++){
        cin >> a[i]; 
    }
    
    for(int i = 0; i < n - 1; i++){
    if(a[i+1] < a[i]){
        moves += (a[i] - a[i+1]); 
        a[i+1] = a[i];            
    }
}
    cout << moves;
    
}
