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
    
    while(t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        
        int ae = 0, ao = 0;
        int be = 0, bo = 0;
        
        for(int j = 0; j < n; j++) {
            if(j % 2 == 0) { 
                if(a[j] == '1') ae++;
                if(b[j] == '1') be++;
            } else {         
                if(a[j] == '1') ao++;
                if(b[j] == '1') bo++;
            }
        }
        
        if(ae == be && ao == bo) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
}