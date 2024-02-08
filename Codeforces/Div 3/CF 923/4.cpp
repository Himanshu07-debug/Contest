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
    int n, q; cin >> n;

    vector<int> arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    vector<int> indx(n);

    indx[n-1] = n;

    for(int i=n-2;i>=0;i--){

        if(arr[i] == arr[i+1]){
            indx[i] = indx[i+1];
        }
        else{
            indx[i] = i+1;
        }

    }

    cin >> q;

    while(q--){

        int l, r; cin >> l >> r;

        l--; r--;

        if(indx[l] > r){
            cout << -1 << " " << -1 << endl;
        }
        else{
            int a = indx[l] + 1;
            int b = l + 1;
            cout << a << " " << b << endl; 
        }

    }

 
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