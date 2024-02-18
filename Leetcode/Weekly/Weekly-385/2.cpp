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

int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

    unordered_map<string, int> m;

    for(int i=0;i<arr1.size();i++){
        string s = to_string(arr1[i]);

        for(int j=1;j<=s.size();j++){
            m[s.substr(0, j)]++;
        }
    }

    int mx = -1;

    for(int i=0;i<arr2.size();i++){

        string s = to_string(arr2[i]);

        for(int j=1;j<=s.size();j++){

            if(m.find(s.substr(0, j)) != m.end()) mx = max(mx, j);
            else break;

        }

    }
    
    if(mx == -1) return 0;
    else return mx;
        
}


};


// int main(){

//     ios::sync_with_stdio(false); cin.tie(NULL);

//     // Your code here
    
    

//     return 0;
// }

