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
    ll n;
    cin >> n;
    ll count = 0; 
    count += n / 100;    
    n = n % 100;         
    count += n / 20;
    n = n % 20;
    count += n / 10;
    n = n % 10;
    count += n / 5;
    n = n % 5;
    count += n / 1; 
    cout << count << '\n';

    
}