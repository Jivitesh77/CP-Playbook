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
    for (int i =0; i < t; i++){
        int n, k;
        cin >> n >> k;
        vi a(n);
        vi b(n);
        for (int i = 0; i < n; i++) { 
                cin >> a[i];
        
    }
    for (int i = 0; i < n; i++) {
            cin >> b[i];
        
    }
    ll experience = 0;
    int comp = 0;
    ll as = 0;
    int bm = 0;
    
     for (int i =0; i < min(n, k); i++){
        as += a[i];
        bm = max(bm, b[i]);
        ll turns_left = k - i - 1;
        ll total = as + turns_left * bm ;
        experience = max(total, experience);



     }
     cout << experience<< endl;

    
    }
    




    
}