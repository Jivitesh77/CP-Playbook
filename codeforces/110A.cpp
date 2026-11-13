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
    vector<int>a;
    int d = (n == 0) ? 1 : std::floor(std::log10(std::abs(n))) + 1;
 
        for (int i=0; i < d; i++){
            int last_digit = n % 10;
            a.push_back(last_digit);
            n /= 10;
        }
        int lucky_count = 0;
for (int i = 0; i < d; i++) {
    if (a[i] == 4 || a[i] == 7) {
        lucky_count++; 
    }
}

if (lucky_count == 4 || lucky_count == 7) {
    cout << "YES";
} else {
    cout << "NO";
}


    


    
}