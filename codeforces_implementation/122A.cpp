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
    vi lucky = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};
    bool ans = 0;
    // Check if n is divisible by any of the lucky numbers
    for (int i = 0; i < 14; i++) {
        if (n % lucky[i] == 0) {
            ans = 1;
            break;
        }
    }
    if(ans){
        cout<<"YES";
    }else{
        cout<<"NO";
    }

    
}
