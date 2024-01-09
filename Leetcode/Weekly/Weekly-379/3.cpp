// https://leetcode.com/problems/maximum-size-of-a-set-after-removals/description/


#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> PBDS;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

class Solution {
public:
    
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();

        unordered_set<int> s1, s2, common;

        for(int x : nums1) s1.insert(x);

        for(int x : nums2){

            s2.insert(x);

            if(s1.find(x) != s1.end()) common.insert(x);

        }

        int n1 = s1.size() , n2 = s2.size(), c = common.size();

        int ans = min(n1 - c, n/2 ) + min(n2 - c, n/2);

        return min(n, ans + c);

    }


};
