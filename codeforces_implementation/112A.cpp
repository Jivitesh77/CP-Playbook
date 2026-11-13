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
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    for (int i =0; i <s1.size(); i++){
        s1[i] = tolower(s1[i]);
        s2[i] = tolower(s2[i]);
    }
    if (s1 < s2){
        cout << -1<<"\n";
    }
    else if (s1 > s2){
        cout << 1<<"\n";
    }
    else{
        cout << 0 << "\n";

    }



    
}