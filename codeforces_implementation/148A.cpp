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
    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;
    int s =0;
    for (int i = 1; i <=d; i++){
        if(i %k == 0 || i % l ==0 || i% m == 0 || i % n == 0){
            s++;

        }
    }
    cout << s;


    
}