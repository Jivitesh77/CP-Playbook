#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> a(m + 2, 0);

        for (int i = 0; i < n; i++){
            int len;
            cin >> len;
            a[len]++;
        }

        vector<int> p(m + 2, 0);
        for(int i = 1; i <= m; i++){
            p[i] = p[i + 1] + p[i];
        }
        
        vector<long long> ans(m + 1, 0);
        
        int kq = std::min(m, 18);
        
        for (int i = 1; i <= m; i++){
            
            vector<long long> now(19, 0);
            
            for (int j = 1; j * i <= m; j++){
                
                
                int count = a[j * i];
                
                int l = j * i + 1;
                int r = std::min(m, (j + 1) * i - 1);
                
                int remain = 0;
                if (l <= r) {
                    remain = p[r] - p[l - 1];                }
                
                for (int k = 1; k <= kq; k++){
                    int limit = (1 << k);
                    long long exact1 = (j <= limit) ? j : (limit - 1);
                    long long remain1 = std::min(j, limit - 1);
                    
                    now[k] += (1LL * count * exact1) + (1LL * remain * remain1);
                }
            }
            
            for (int k = 1; k <= kq; k++){
                ans[k] = std::max(ans[k], now[k]);
            }
        }
        
        for (int k = 1; k <= m; k++){
            if (k <= 18) {
                cout << ans[k] << " ";
            } else {
                // For any k > 18, just print the answer for 18
                cout << ans[18] << " ";
            }
        }
        cout << "\n";
    
    }
}