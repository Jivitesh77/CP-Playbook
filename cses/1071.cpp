#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        long long y, x;
        cin >> y >> x;

        long long z = max(y, x);
        
        long long inner_square_area = (z - 1) * (z - 1);
        long long ans;

        if (z % 2 == 0) {
            if (x == z) {
                ans = inner_square_area + y;
            } else {
                ans = (z * z) - x + 1;
            }
        } else {
            if (y == z) {
                ans = inner_square_area + x;
            } else {
                ans = (z * z) - y + 1;
            }
        }

        cout << ans << "\n";
    }

}