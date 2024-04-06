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

class Solution {
public:
    int fun(int i, int j, int sum, vector<int> &arr, vector<vector<int>> &dp){

    if(j - i < 1) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int c1 = 0, c2 = 0, c3 = 0;

    if(arr[i] + arr[i+1] == sum){
        c1 = 1 + fun(i+2, j, sum, arr, dp);
    }

    if(arr[i] + arr[j] == sum){
        c2 = 1 + fun(i+1, j-1, sum, arr, dp);
    }

    if(arr[j] + arr[j-1] == sum){
        c3 = 1 + fun(i, j-2, sum, arr, dp);
    }

    return dp[i][j] = max(c1, max(c2, c3));


}

int maxOperations(vector<int>& arr) {

    int n = arr.size();

    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2001, -1)));
    vector<vector<int>> dp(n, vector<int>(n, -1));

    // You can take single DP

    int mx = 0;

    mx = max(mx, fun(1, n-2, arr[0] + arr[n-1], arr, dp));

    dp = vector<vector<int>>(n, vector<int>(n, -1));
    mx = max(mx, fun(2, n-1, arr[0] + arr[1], arr, dp));

    dp = vector<vector<int>>(n, vector<int>(n, -1));
    mx = max(mx, fun(0, n-3, arr[n-1] + arr[n-2], arr, dp));

    return mx + 1;
        
}

};