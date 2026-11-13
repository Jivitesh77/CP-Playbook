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
    int n, h;
    cin >> n >> h;
    int w = 0;
    vector<int> a(n);
    for (int i =0; i <n; i++){
        cin>> a[i];
    }
    for(int i =0; i< n; i++){
        if(a[i] > h){
            w = w+2;

        }else{
            w++;
        }

    }
    cout << w;



    
}