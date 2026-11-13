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
    for(int i =0; i < t; i++){
        int n;
        cin >> n;
        vi b(n);
        for(int j = 0; j < n; j++){ 
            cin >> b[j];
        }
        vi d(n + 1, 0);
        for(int j = 0; j < n; j++){
            if(b[j] > 0){
                int l = max(0, j - b[j] + 1);
                int r = min(n - 1, j + b[j] - 1);
                if(l <= r){
                    d[l]++;
                    d[r + 1]--;
                }
            }
        }
        string ans(n, '1');
        int c = 0;
        bool tr = false;
        for(int j = 0; j < n; j++){
            c += d[j];
            if(c > 0){
                ans[j] = '0';
            }
            else {
                tr = true;
            }
        }
        if(!tr){
            cout << -1 << "\n";
            continue;
        }
        vi ld(n, 1e9);
        vi rd(n, 1e9);
        int ls1 = -1e9;
        for(int j = 0; j < n; j++){
            if(ans[j] == '1'){
            ls1 = j;
        }
            if(ls1 != -1e9){

            ld[j] = j - ls1;
        }
        }
        ls1 = 1e9;
        for(int j = n - 1; j >= 0; j--){
            if(ans[j] == '1'){ 
                ls1 = j;
            }
            if(ls1 != 1e9){ 
                rd[j] = ls1 - j;
            }
        }
        bool q = true;
        for(int j = 0; j < n; j++){
            if(b[j] != -1){
                if(min(ld[j], rd[j]) != b[j]){
                    q = false;
                    break;
                }
            }
        }
        if (q) {
            cout << ans << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}