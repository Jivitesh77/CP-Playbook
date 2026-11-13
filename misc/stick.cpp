#include <climits>
#include <iostream>
#include <iostream>
#include <algorithm>

using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int parts;
	cin >> parts;
	int lengt_each[parts];
	int total_sum = 0;
	int left_sum =0;
	int min_diff = INT_MAX;
	for (int i = 0; i < parts; i++){
		cin >> lengt_each[i];
		total_sum += lengt_each[i];

	}
	
	
	
	for (int i =0; i < parts - 1; i++){
		left_sum += lengt_each[i];
		int right_sum = total_sum - left_sum;
		min_diff = min(min_diff, abs(left_sum - right_sum));
		
		
	}
	cout << min_diff << endl;




}