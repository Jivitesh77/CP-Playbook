#include <iostream>

using namespace std;
using ll = long long;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    for (ll k = 1; k <= n; k++) {
        ll total_ways = (k * k * (k * k - 1)) / 2;
        
        ll attacking_ways = 4 * (k - 1) * (k - 2);
        
        // Valid ways
        cout << total_ways - attacking_ways << "\n";
    }
}