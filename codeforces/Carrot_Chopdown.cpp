	#include <bits/stdc++.h>
	using namespace std;
	int main(){
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		int t;
		cin >> t;
		while(t--){
			int n,m;
			cin>>n>>m;
			vector<int> a(m+1, 0);
			for (int i =0; i < n; i++){
				int len;
				cin >> len;
				a[len]++;
			}
			vector<int> s(m+2, 0);
			for(int i = m; i >=1; i--){
				s[i] = s[i+1] + a[i];



			}
			int max = 0;
			for (int i = 1; i <= m; i++){
				int now = s[i];
				int extra = (2 * i <= m) ? a[2 * i] : 0; 
				max = std::max(max, s[i] + extra);



			}
			cout<<max<<"\n";



		}



	}