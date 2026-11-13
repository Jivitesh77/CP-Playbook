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
    int upper =0;
    int lower=0;
    for (int i =0; i < s.size(); i++){
        if(isupper(s[i])){
            upper++;
        }else{
            lower++;
        }
    }
    if(lower > upper){
        for (int i =0; i <s.size(); i++){
            s[i] = tolower(s[i]);
        }
    }else if(upper > lower){
        for (int i=0; i <s.size(); i++){
            s[i] = toupper(s[i]);
        }
    }else{
        for (int i =0; i <s.size(); i++){
            s[i] = tolower(s[i]);
        
}
    }
    cout << s;


    
}