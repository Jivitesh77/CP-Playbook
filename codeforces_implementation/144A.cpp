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
    vector<int> a(n);
    int m = 0;
    int l = 0;
    for(int i = 0; i <n; i++){
        cin >> a[i];
    }
for (int i = 0; i < n; i++) {
    if (a[i] > a[m]) {
        m = i;
    }
    if (a[i] <= a[l]) {
        l = i;
    }
}
int swaps = m + ((n - 1) - l);
if (m > l) {
    swaps--; 
}
cout << swaps << '\n';
}