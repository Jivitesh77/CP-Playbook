#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
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
    ll n, l;
    cin >> n >> l;
    vll a(n+1, 0);
    for(int i=1; i<n+1; i++){
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    ll maxdist = 0;
    for(int i=2; i<n+1; i++){
        ll dist = a[i] - a[i-1];
        maxdist = max(dist, maxdist);
    }
    double ans = max({maxdist/2.0 , max( (double) (a[1] - 0), (double)(l - a[n]) )});
    cout << fixed << setprecision(10) << ans;


    
}
