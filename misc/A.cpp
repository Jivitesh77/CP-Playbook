#include <iostream>
#include <cctype>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	string S;
	cin >> S;
	bool is_upper_all = true;
	for (char c : S){
		if (!std::isupper(c)){
			is_upper_all = false;
			break;
		}
	}
	if (is_upper_all && 1<= S.size() && S.size() <= 100){
		for (int i = 0; i < S.size(); i++){
			if (S[i] != 'A') {
            S[i] = '.'; 
        }
		}
		cout << S << endl;
		

	}


	

}