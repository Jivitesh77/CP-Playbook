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
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        string s;
        cin >> s;

        int o1 = 1, o2 = 1;
    int e1 = 1, e2 = 1;

    for (int j = 0; j < n; j++) {
        if (s[j] == '?') continue; 
        if (j % 2 == 0) {
            char eo1 = ((j / 2) % 2 == 0) ? '0' : '1';
            char eo2 = ((j / 2) % 2 == 0) ? '1' : '0';
            
            if (s[j] != eo1) o1 = 0;
            if (s[j] != eo2) o2 = 0;
        } else {
            char ee1 = ((j / 2) % 2 == 0) ? '0' : '1';
            char ee2 = ((j / 2) % 2 == 0) ? '1' : '0';
            
            if (s[j] != ee1) e1 = 0;
            if (s[j] != ee2) e2 = 0;
        }
    }

    
    int total = (o1 + o2) * (e1 + e2);
    cout << total << '\n';
            

            }

        }