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
bool string_lowercase(string s){
    for (char c : s){
        if (!std::islower(c)) {
            return false;
        }
    }
    return true;

    }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    cin >> ws;
    if (n >= 1 && n <= 100){
    vector<string> s(n);
    for (int i =0; i < n; i++){
        getline( cin,s[i]);
    }

    
    for (int i =0; i < n; i++){
        if (s[i].length() >=1 && s[i].length() <= 100){
    if (s[i].length() > 10){
        cout << s[i][0];
        cout << s[i].length() - 2;
        cout << s[i][s[i].length() - 1] << "\n";
        

    }else{
        cout << s[i];
        cout << "\n";
    }
}
}
}
}
    
