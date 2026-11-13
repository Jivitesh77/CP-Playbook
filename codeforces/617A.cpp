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
    int d = 0;
    int x;
    cin >> x;
    int dist = x - d;
    int steps = 0;
    int max_step;
    while(dist != 0){
        max_step = min(dist, 5);
        dist -= max_step;
        steps++;

    }
    cout << steps;




    
}