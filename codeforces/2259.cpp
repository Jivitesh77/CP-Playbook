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
    cin >>t;
    for (int i = 0; i < t; i++)
    {
       int n;
    cin >> n;
    vector<int> a(n);
    
    int f = -1;
    int l = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != 0) {
            if (f == -1) {
                f = i;
            }
            l = i;      
        }
    }
    
     for (int i = 0; i < n; i++) {
        if (a[i] == -1) {
            if (i == f || i == l) {
                a[i] = 1;
            } else {
                a[i] = 0;
            }
        }
        cout << a[i] << " ";
    }
    cout << '\n';
}

    
}
