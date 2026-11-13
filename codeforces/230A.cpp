#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int s, n;
    cin >> s >> n;
    
    // map<strength, total_bonus>
    map<int, int> dragons;
    
    while(n--){
        int a, b;
        cin >> a >> b;
        dragons[a] += b; 
    }
    for(auto const& [strength, bonus] : dragons){
        if(s > strength){
            s += bonus;
        } else {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}