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
    set<int>l;
    int x, y;
    cin >> x;
    int p;
    for (int i =0; i < x; i++){
        cin >> p;
        l.insert(p);


    }
    int q;
    cin >> y;
    for (int i = 0; i < y; i++){
        cin >> q;
        l.insert(q);
    }
    if (l.size() == n){
        cout<<"I become the guy.";
    }else{
        cout<<"Oh, my keyboard!";
    }



    
}