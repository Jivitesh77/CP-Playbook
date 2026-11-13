#include <bits/stdc++.h>
using namespace std;


using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

void findSubarrayWithSum(const vector<int>& arr, int target){
    int current_sum = 0;
    int left = 0;
    for (int right = 0; right < arr.size(); right ++){
        current_sum +=arr[right];
        while (current_sum > target && left <= right){
            current_sum -=arr[left];
            left++;
        }
        if (current_sum == target){
            cout << "Found subarray from index" << left << "to " << right << "\n";
            return;
        }
        
    }
    cout << "No subarray found with the given sum.\n";
}
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
    int target;
    for(int i =0; i < n; i++ ){
        cin >> a[i];
    }
    cin >> target;
    findSubarrayWithSum(a, target);


    
}