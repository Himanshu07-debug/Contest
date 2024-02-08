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

    vector<int> arr(2*n);

    for(int i=0;i<2*n;i++) cin >> arr[i];

    deque<int> dq;

    set<int> s;

    for(int i=0;i<2*n;i++){

      if(s.find(arr[i])!= s.end()){

        dq.push_front(arr[i]);
        s.erase(s.find(arr[i]));

      }
      else{
        s.insert(arr[i]);
      }

    }

     while(!dq.empty()){

      cout << dq.front() << " ";
      dq.pop_front();

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