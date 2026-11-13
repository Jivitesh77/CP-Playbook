#include <bits/stdc++.h>
#include <iomanip>
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
    int t;
    cin >> t;
    int n, d, h;
    
    for (int i=0; i < t; i++){
        cin >> n >> d >> h;
        vector<double> y(n);
        for (int j =0; j < n; j++){
            cin >> y[j];
        }
        double area = n * (0.5 * d * h);
        for (int j =0; j < n -1; j++){
            if (y[j + 1] < y[j] + h){
                double hover = (y[j] + h) - y[j + 1];
                double b = d * (hover / h);

                area -= (0.5 * b * hover);
            }
        }
        cout << fixed << setprecision(7) << area << "\n";

    }



    
}