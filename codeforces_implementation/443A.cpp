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
    set<char>a;
    char c;
    char b;
    cin >> b;
    cin >> ws;
    if (cin.peek() == '}') {
        cin >> b;
    }else{
    while(cin >> c >> b){
        a.insert(c);
        if(b == '}'){
            break;
        }

    }
}
    cout << a.size();


    
}