#include <bits/stdc++.h>
#include <cctype>
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
    for(int i=0; i< s.size(); i++){
        s[i] = tolower(s[i]);
    }
    string result = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' && s[i] != 'y') {
            result += '.';
            result += s[i];
        }  
    }
    cout << result << '\n';


    
}
