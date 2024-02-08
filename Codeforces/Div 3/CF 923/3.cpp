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
    int n, m, k; cin>>  n >> m >> k;

    vector<int> arr(n), brr(m);

    for(int i=0;i<n;i++) cin >> arr[i];

    for(int i=0;i<m;i++) cin >> brr[i];

    set<int> s1, s2, s3;

    for(int i=0;i<n;i++){
        if(arr[i] <= k){
        s1.insert(arr[i]);
        }
    }

    if(s1.size() < k/2){
        cout << "NO" << endl;
        return;
    }

    for(int i=0;i<m;i++){

        if(brr[i] <= k) s2.insert(brr[i]);
    }

    if(s2.size() < k/2){
        cout << "NO" << endl;
        return;
    }

    for(auto x: s1) s3.insert(x);

    for(auto y : s2) s3.insert(y);

    if(s3.size() >= k) cout << "YES" << endl;
    else cout << "NO" << endl;

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