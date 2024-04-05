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

int fun(int i, int j, vector<vector<bool>> &visited, vector<vector<int>> &arr, int n, int m){

    queue<pair<int,int>> q;

    int ans = 0;

    q.push({i, j});

    visited[i][j] = true;

    pair<int,int> dir[4] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

    while(!q.empty()){

        auto [a, b] = q.front();
        q.pop();

        ans += arr[a][b];

        for(auto [x, y] : dir){

            int x1 = a + x;
            int y1 = b + y;

            if(x1 >= 0 && y1 >= 0 && x1 < n && y1 < m){

                if(arr[x1][y1] > 0 && visited[x1][y1] == false){
                    q.push({x1, y1});
                    visited[x1][y1] = true;
                }

            }

        }

    }

    return ans;


}

int findMaxFish(vector<vector<int>>& arr) {

    int n = arr.size(), m = arr[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int mx = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(arr[i][j] > 0 && visited[i][j] == false){
                int ans = fun(i, j, visited, arr, n, m);
                mx = max(mx, ans);
            }

        }
    }

    return mx;

}

};


// int main(){

//     ios::sync_with_stdio(false); cin.tie(NULL);

//     // Your code here
    
    

//     return 0;
// }

