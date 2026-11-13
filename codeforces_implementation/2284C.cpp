#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long a, b;
        scanf("%lld %lld", &a, &b);

        if (a == b) { printf("0\n"); continue; }
        if (__gcd(a, b) == 1) { printf("1\n%lld\n", b - a); continue; }

        // try two operations: a -> c -> b
        long long found = -1;
        for (long long c = a + 1; c < b; c++) {
            if (__gcd(c, a) == 1 && __gcd(c, b) == 1) { found = c; break; }
        }
        if (found != -1) {
            printf("2\n%lld %lld\n", found - a, b - found);
            continue;
        }

        // no c exists, so the interval is tiny: DP over all values a..b
        int L = (int)(b - a + 1);
        const int INF = INT_MAX;
        vector<int> dp(L, INF), par(L, -1);
        dp[0] = 0;
        for (int j = 1; j < L; j++) {
            for (int i = 0; i < j; i++) {
                if (dp[i] == INF) continue;
                if (__gcd(a + i, a + j) == 1 && dp[i] + 1 < dp[j]) {
                    dp[j] = dp[i] + 1;
                    par[j] = i;
                }
            }
        }

        vector<long long> xs;
        for (int j = L - 1; j != 0; j = par[j]) xs.push_back(j - par[j]);
        reverse(xs.begin(), xs.end());

        printf("%d\n", (int)xs.size());
        for (size_t i = 0; i < xs.size(); i++)
            printf("%lld%c", xs[i], i + 1 < xs.size() ? ' ' : '\n');
    }
    return 0;
}