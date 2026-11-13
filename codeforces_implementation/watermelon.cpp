#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int w;
    cin >> w;
    if (w >= 1 && w<= 100){
        if ( w % 2 == 0 && w != 2){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;


    }


    
}