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
    
    vi a(n-1);
    for(int i = 0; i < n-1; i++){
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    for(int i = 0; i < n-1; i++){
        if(a[i] != i + 1){
            cout << i + 1 << endl;
            return 0; }
    }
    
    cout << n << endl;
    return 0;
}