#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> PBDS;

typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> PBDSP;


#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;


long long minOperationsToMakeMedianK(vector<int>& arr, int k) {

    sort(arr.begin(), arr.end());

    long long op1 = 0;

    int n = arr.size();

    if(arr[n/2] == k) return 0;

    if(arr[n/2] < k){

        for(int i = n/2; i < n;i++){
            if(arr[i] < k){
                op1 += abs(arr[i] - k);
            }
            else break;
        }

    }
    else{

        for(int i=n/2;i>=0;i--){
            if(arr[i] > k){
                op1 += abs(arr[i] - k);
            }
            else break;
        }

    }

    return op1;
        
}


// int main(){

//     ios::sync_with_stdio(false); cin.tie(NULL);

//     // Your code here
    
    

//     return 0;
// }