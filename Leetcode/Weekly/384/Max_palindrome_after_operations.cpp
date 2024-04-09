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

// You are given a 0-indexed string array words having length n and containing 0-indexed strings.
// You are allowed to perform the following operation any number of times (including zero):
// Choose integers i, j, x, and y such that 0 <= i, j < n, 0 <= x < words[i].length, 0 <= y < words[j].length, and swap the
//  characters words[i][x] and words[j][y].
// Return an integer denoting the maximum number of palindromes words can contain, after performing some operations.
// Note: i and j may be equal during an operation.

// Input: words = ["abbb","ba","aa"]
// Output: 3
// Explanation: In this example, one way to get the maximum number of palindromes is:
// Choose i = 0, j = 1, x = 0, y = 0, so we swap words[0][0] and words[1][0]. words becomes ["bbbb","aa","aa"].
// All strings in words are now palindromes.
// Hence, the maximum number of palindromes achievable is 3.




// LEARNING 1 -------->> Position do not matter

// LEARNING 2 --------->> We want maximum no. of Palindrome, so start making smallest length palindrome first



static bool cmp(const string &s1, const string &s2){
        return s1.size() < s2.size();
}


int maxPalindromesAfterOperations(vector<string>& arr) {

    int cnt[256] = {0};

    for(auto x : arr){
        for(auto c : x){
            cnt[c]++;
        }
    }

    // its palindrome, so we will store even pairs cnt and odd cnt
    int odd = 0, even = 0;

    for(int x : cnt){

        if(x > 0){

            if(x & 1){
                even += x/2;
                odd += 1;
            }
            else{
                even += x/2;
            }

        }

    }

    sort(arr.begin(), arr.end());

    int c = 0;

    for(auto x : arr){

       if(x.size() & 1){

        if(odd) odd--;
        else{
            // Take odd from 1 even pair --> 1 even pair get used, 1 odd used in Palindrome making, and the remaining will contri to odd cnt
            even--;
            odd++;
        }

       }

       if(even < x.size()/2) break;

       even -= x.size()/2;

       c++;

       

    }

    return c;
    
}




// int main(){

//     ios::sync_with_stdio(false); cin.tie(NULL);

//     // Your code here
    
    

//     return 0;
// }