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
    string s;
    cin >> s;
    string t = "hello";
    int j = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == t[j]) {
            j++;
        }
    }
    if (j == 5) {
        cout << "YES";
    }else{
        cout << "NO";        
    }

        
}
