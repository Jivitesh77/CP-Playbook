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
int maxSubArraySum(const vector<int>& arr){
    int max_so_far = INT_MIN;
    int current_sum = 0;
    for (int i = 0; i < arr.size(); i++){
        current_sum += arr[i];
        if (current_sum > max_so_far)
{
    max_so_far = current_sum;
}
if (current_sum < 0){
    current_sum = 0;
}
}  
return max_so_far ; 
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans = maxSubArraySum(a);
    cout << ans << "\n";

    
}