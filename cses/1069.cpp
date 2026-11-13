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
    string n;
    cin >> n;
    int c_g = 0;
    int c_a = 0;
    int c_T = 0;
    int c_c = 0;
    int max = 1;
    int temp = 1;
    for(int i=0; i<n.length()-1; i++){
        
        if(n[i] == n[i+1]){
        temp++;
    } else {
        temp = 1;
    }
    max = std::max(max, temp);    
    
}
cout << max;
}
