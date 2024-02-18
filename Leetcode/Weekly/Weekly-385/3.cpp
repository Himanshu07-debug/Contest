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

bool isPrime(int n){

    if(n == 1) return false;

    for(int i=2;i*i <= n;i++){
        if(n % i == 0) return false;
    }

    return true;

}

int mostFrequentPrime(vector<vector<int>>& mat) {

    unordered_map<int, int> mp;

    int m = mat.size() , n = mat[0].size();

    int dir[8][2] = { {0, 1} , {0, -1} , {1, 0} , {-1, 0} , {1, -1} , {-1, 1}, {-1, -1} , {1, 1} };

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){

            for(int k = 0; k < 8 ;k++){

                int num = 0;

                int x = i , y = j;

                while(x >= 0 && y >= 0 && x < m && y < n){

                    num = num*10 + mat[x][y];

                    if(num > 10 && isPrime(num) == true){
                        mp[num]++;
                    }

                    x = x + dir[k][0];
                    y = y + dir[k][1];

                }

            }

        }
    }

    int mx = -1;
    int mxf = 0;

    for(auto [a, b] : mp){
        
        // cout << a << " " << b << endl;

        if(b > mxf){
            mx = a;
            mxf = b;
        }
        else if(b == mxf){
            if(a > mx) mx = a;
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

