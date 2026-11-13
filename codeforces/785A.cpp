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
    int n;
    cin >> n;
    int sd=0;
    vector<string>s(n);
    for (int i=0; i<n; i++){
        cin >> s[i];
        if (s[i] == "Icosahedron"){
            sd += 20;
        }else if(s[i] == "Cube"){
            sd += 6;
        }else if(s[i] == "Tetrahedron"){
            sd +=4;
        }else if(s[i] == "Dodecahedron"){
            sd +=12;
        }else{
            sd += 8;
        }
    }
    cout << sd;



    
}