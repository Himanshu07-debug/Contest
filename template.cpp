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

int minimumTimeToInitialState(string s, int k) {

    int c = 0;

    c++;

    for(int i=k;i<s.size();i+=k){

        string tmp1 = s.substr(0, s.size() - i);

        string tmp2 = "";

        for(int j=i;j<s.size();j++) tmp2 += s[j];

        if(tmp1 == tmp2) return c;
    
        c++;

    }

    return c;
        
}

};


// int main(){

//     ios::sync_with_stdio(false); cin.tie(NULL);

//     // Your code here
    
    

//     return 0;
// }

