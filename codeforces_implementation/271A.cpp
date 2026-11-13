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
    int y;
    cin >>y;
    while(true){
        y++;
        int a = y / 1000;
        int b = (y /  100) % 10;
        int c = (y / 10) % 10;
        int d = y % 10;
        if(a!=b && b!=c && c!=d && c!=a && a!=d && b!=d){
            cout << y << endl;
            break;
            
        }


    }


    
}