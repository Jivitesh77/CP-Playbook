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
    string input;
    cin >> input;
    stringstream ss(input);
    string number;
    vector<int> a;
    
    while(getline(ss, number, '+')){
        a.push_back(stoi(number));

    }
    sort(a.begin(), a.end());
    for (int i=0; i < a.size(); i++){
        cout << a[i] << (i != a.size() - 1 ? "+" : "");
        }
    }



    
