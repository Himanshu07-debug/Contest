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

bool pred(vector<int> &arr, vector<int> &brr, int mid){

    vector<int> lastIndx(arr.size(), -1);

    for(int i = 0; i <= mid ; i++){

        lastIndx[brr[i] - 1] = i;

    }

    for(int i = 0 ; i < arr.size() ; i++){
        if(lastIndx[i] == -1) return false;
    }

    int power = 0;
    // int cnt = 0;

    for(int i = 0 ;i <= mid; i++){

        if(i == lastIndx[brr[i] - 1]){

            if(power >= arr[brr[i] - 1]){
                power -= arr[brr[i] - 1];
                // cnt++;
            }
            else return false;

        }
        else power++;

    }

    return true;


}

int earliestSecondToMarkIndices(vector<int>& arr, vector<int>& brr) {

    int l = 0, r = brr.size() - 1, ans = -1;

    while(l <= r){

        int mid = (l + r)/2;

        if(pred(arr, brr, mid)) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;

    }

    return (ans != -1) ? ans + 1 : ans;

}




// int main(){

//     ios::sync_with_stdio(false); cin.tie(NULL);

//     // Your code here
    
    

//     return 0;
// }

