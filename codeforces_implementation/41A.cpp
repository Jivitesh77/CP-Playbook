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
    string s, t;
    cin >> s;
    cin >> t;
    int mistake = 0;
    if (s.size() == t.size()){
    for (int i =0; i < s.size(); i++){
        if(s[i] != t[s.size() - 1 - i ]){
            mistake++;

        } 
    }
    if(mistake > 0){
    cout<< "NO";
}else{
    cout<<"YES";
}
}else{
    cout << "NO";
}



    
}