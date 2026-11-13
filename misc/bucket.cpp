#include <bits/stdc++.h>

int main(){
    using namespace std;
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int number_buckets;
    cin >> number_buckets;
    
    int amt[number_buckets];
    int max_capacity[number_buckets];
    for (int i = 0; i < number_buckets; i++){
        cin >> max_capacity[i];
    }
    for (int i = 0; i < number_buckets; i++){
        cin >> amt[i] ;
    }
    for (int i = 0; i < number_buckets - 1; i++){
        int amt_fill = min(amt[i], max_capacity[i+1] - amt[i+1]);
        amt[i] -= amt_fill;
        amt[i + 1] += amt_fill;
    }
    for (int i = 0; i < number_buckets; i++){
        cout<<amt[i]<<" ";
    }
    cout<<endl;

}