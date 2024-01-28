// LINK --> https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/description/

// 3rd one -> PBDS

// Here, Greedily soch to liye when it will be possible to get make all elements as 1 ... 
// GCD value decreases or remain same when we move in the array like Prefix. Agar prefix GCD 1 mila , POSSIBLE, otherwise NOT.
// Only We have to make only one element as 1, wo baaki sabko 1 kar denga....

// But the case when 1 is not there in the array, and ek baar adjacent ko solve krke GCD 1 nhi aara, then how to find the part of consecutive 
// numbers jo GCD 1 de in min. no. of operation..
// We will find the min. sized Subarray with GCD == 1. its operation will be least as compare from all combinations -> size - 1

// GCD prefix me consider kiye becz ek hi pair ko baar - baar GCD krke uski GCD 1 nhi kar sakte agar wo number divisible hai kisi no. se..


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
    int minOperations(vector<int>& nums) {
        
        int val = 0;
        int cnt=0;
        for(int x:nums){
            val = __gcd(val,x);
            if(x==1){
                cnt++;
            }
        }
        if(val!=1){
            return -1;
        }
        if(cnt!=0){
            return nums.size()-cnt;
        }
        
        int min_sz = 100;
        
        for(int i=0;i<nums.size();i++){

            int val = 0;

            for(int j=i;j<nums.size();j++){

                 val = __gcd(val,nums[j]);

                    if(val==1){
                        min_sz = min(min_sz,j-i+1);
                    }

            }

        }
        
        return min_sz - 1 + nums.size() - 1;
        
    }
};
