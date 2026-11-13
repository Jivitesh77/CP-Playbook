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
bool isCapitalizedProperly(const string& str) {
    if (str.empty()) return false;
    for (size_t i = 1; i < str.length(); ++i) {
        if (!isupper(static_cast<unsigned char>(str[i]))) {
            return false; 
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    
    if (isCapitalizedProperly(s)) {
        for (size_t i = 0; i < s.length(); ++i) {
            if (isupper(static_cast<unsigned char>(s[i]))) {
                s[i] = tolower(static_cast<unsigned char>(s[i]));
            } else {
                s[i] = toupper(static_cast<unsigned char>(s[i]));
            }
        }
    }
cout << s;
    


    
}
