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
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int j = 0; j < n; j++){
            cin >> a[j];
        }
        for(int j = 0; j < n; j++){
            if(a[j] == 1){
                break;
            }
            else if(a[j] == -1){
                a[j] = 1;
                break;
            }
        }
        for(int j = n - 1; j >= 0; j--){
            if(a[j] == 1){
                break;
            }
            else if(a[j] == -1){
                a[j] = 1;
                break;
            }
        }
        for(int j = 0; j < n; j++){
            if(a[j] == -1){
                a[j] = 0;
            }
            cout << a[j] << " ";
        }
        cout << "\n";
    }
}