#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int left = 0;
    std::cin >> n;
    int right = n -1;
    int x;

vector<int> arr(n);
for (int i =0; i < n; i++){
    cin >> arr[i];
}
cin >> x;
sort(arr.begin(), arr.end());
while (left < right){
    if (arr[left] + arr[right] == x){

        cout << "found" << "\n";
        cout << arr[left] << " " << arr[right] << "\n";
        break;
    }else if(arr[left] + arr[right] < x){
        left++;

    }else{
        right--;
    }
}
while(left >= right){
    cout << "Not Found";
    break;
}
   
}