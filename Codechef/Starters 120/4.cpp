#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> PBDS;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> PBDSp;


#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;


void solve() {

    // Your Code here
    int n; cin >> n;

    vector<int> arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    vector<int> cnt(n+1, 1);

    int sum = 0;

    int i = 0, j = 0;

    while(j < n){

      sum += arr[j];

      if(j == 0){
          j++;
          continue;
      }

      while(i <= j && sum > n){
        sum -= arr[i];
        i++;
      }

      if(j - i > 0){

        int z = i;
        int c = sum;
        
        while(z < j && c > 0){

          cnt[c]++;
          c -= arr[z];
          z++;

        }
        

      }

      j++;

    }

    for(int i=1;i<=n;i++){
      cout << cnt[i] << " ";
    }

    cout << endl;
}

// LOGIC -------------------------------------------->>

// LOGIC --------------------------------------->>

// An Observation Based Problem ...

// Permutation will consist all distinct no.s.
// The sum of the Whole array will be --> n * (n + 1)/2 
// This sum Should <= n...

// Math --> 
// Taking any Subarray of length l --> 1 <= l <= n
// l * (l + 1)/2 <= n
// Reducing --> l <= sqrt(2 * n)


// Therefore, Any Subarray cant be of the lenght > sqrt(n)

// Trying all Subarrays --> O(n * sqrt(n))  ==> 1e5 * 1e2


void solve(){

    int n; cin >> n;

    vector<int> arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    vector<int> cnt(n+1);

    for(int i=0;i<n;i++){

        int sum = 0;

        for(int j=i;j<n;j++){

            sum += arr[i];

            if(sum <= n) cnt[sum]++;
            else break;

        }

    }

    for(int i=1;i<=n;i++){
      cout << cnt[i] << " ";
    }

    cout << endl;



}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}