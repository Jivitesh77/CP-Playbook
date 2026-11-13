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
    int n;
    ll k;
    for(int i=0; i < t; i++){
        cin >> n >>k;
        vector<long long> a(n+1);
        vector<long long>p(n+1, 0);
        vector<long long>v (n+1);
    
        for(int j=1; j <= n; j++){
            cin >> a[j];
            p[j] = p[j -1] + a[j];
            v[j] = a[j] - j * k;
        }
        for(int j = 1; j <= n; j++){
            if(j == 1 || j == n){
                cout << 0 << (j == n ? "" : " ");
                continue;
            }
            ll u = a[j - 1] - j * k;
            ll l = j +1;
            ll h = n;
            ll r = j;
            while(l <= h){
                int m = l + (h - l)/ 2;
                if(v[m] > u){
                    r = m;
                    l = m +1;


                }else{
                    h = m -1;

                }
            }
            ll len = r - j;
            if(len > 0){
                ll s = p[r] - p[j];
                ll b = len *a[j - 1];
                ll kd = (len * (len +1)/2)* k;
                cout << s - b - kd << " ";

            } else{
                cout << 0 << " ";
            }
        }
        cout<<"\n";

    }



    
}