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

#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;


// We have a horizontal number line. On that number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], 
// where n = size of the stations array. Now, we add k more gas stations so that d, the maximum distance between adjacent gas stations, 
// is minimized. We have to find the smallest possible value of d. Find the answer exactly to 2 decimal places.

// n = 10
// stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
// k = 9
// Output: 0.50
// Explanation: Each of the 9 stations can be added mid way between all the existing adjacent stations.

// n = 10
// stations = [3,6,12,19,33,44,67,72,89,95] 
// k = 2 
// Output: 14.00 
// Explanation: Construction of gas stations at 8th(between 72 and 89) and 6th(between 44 and 67) locations.


// LOGIC --------------------------------------------------------------->>>

// keywords are of BS 
// We have to minimize the distance value....

// we will be query on this distance.... 
// min dist = 0, max_dist = last_element - first_element


// PREDICATE LOGIC ------------------------->>
// while querying a distance d....
// How many stations will be required if I try to ensure that the max_dist between any 2 stations will be atmost d
// if cnt is <= k --> TRUE, otherwise false

bool check(vector<int> &arr, int k, double m){

    int cnt = 0;

    for(int i=1;i<arr.size();i++){

        cnt += (arr[i] - arr[i-1])/m;

    }

    return (cnt <= k);

}


double findSmallestMaxDist(vector<int> &arr, int k) {
    
    double l = 0, r = 0;

    for(int i=1;i<arr.size();i++){
        r = max(r, (arr[i] - arr[i-1])*1.0);
    }


    // 50 is enough ---> log2(1e9 * 1e2)

    for(int i=0;i<50;i++){

        double m = (l + r)/2;

        if(check(arr, k, m)) r = m;
        else l = m;

    }

    return r;
        
}


// another way of solving decimal one's

double findSmallestMaxDist(vector<int> &stations, int K) {
    
    double low = 0;
    int n = stations.size();

    double high = stations[n - 1] - stations[0];

    while (high - low >= 1e-2) {

        double mid = (low + high) / 2.0;

        if (!check(stations, K, mid)) {
            low = mid;
        } else {
            high = mid;
        }

    }

    return high;
}


// more another way


double findSmallestMaxDist(vector<int> &stations, int K) {
    
    double low = 0;
    int n = stations.size();

    double high = stations[n - 1] - stations[0];

    double ans = 0;

    while (low <= high) {

        double mid = (low + high) / 2.0;

        if (check(stations, K, mid)) {
            ans = mid;
            high = mid - 0.01;              // becz only 2 precision was there -->if 6 then 0.000001
        } else {
            low = mid + 0.01;
        }

    }

    return ans;
}

