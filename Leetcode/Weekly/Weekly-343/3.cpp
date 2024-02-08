// LINK --> https://leetcode.com/contest/weekly-contest-343/problems/minimum-cost-of-a-path-with-special-roads/

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

// Learnings -------------------------------------->>>

// Here, from a source to the destination in shortest path , DIJKSTRA ( Greedy, DP TLE Denge )

// But see the Constraint, You cant make the Grid i.e Graph. 1 <= m, n <= 10^5

// In Such type of Questions, Jab Graph hi HOPE ho but Grid nhi bna sakte.. you will Observe that always there something extra is given in Such Q.s

// SpecialRoads Array. With the help of this array, we will make a Graph with all Possible edges. PHOTO
// Also see the SpecialRoads Array length Constraint -> We can use it for quadratic

// Becz Minimum Path 2 hi case se honga --> Either Special Edge Include krke yaa direct Move krke without using Special Edge... therefore we will
// Consider this in our Graph

// Edge length is easy -> Formula --> O(1)


class Solution {
public:

int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& arr) {
        
    map<pair<int,int>, vector<pair<int, pair<int,int>>>> gr;

    int sti = start[0] , stj = start[1];
    int ti = target[0] , tj = target[1];

    gr[{sti, stj}].push_back({abs(sti - ti) + abs(stj - tj), {ti, tj}});

    for(int i=0; i<arr.size() ; i++){

        int i1 = arr[i][0], j1 = arr[i][1], i2 = arr[i][2] , j2 = arr[i][3], c = arr[i][4];

        // Edges with starting and ending vertex

        gr[{sti, stj}].push_back({abs(sti - i1) + abs(stj - j1), {i1, j1}});
        gr[{i1, j1}].push_back({abs(sti - i1) + abs(stj - j1), {sti, stj}});

        gr[{ti, tj}].push_back({abs(ti - i1) + abs(tj - j1), {i1, j1}});
        gr[{i1, j1}].push_back({abs(ti - i1) + abs(tj - j1), {ti, tj}});

        gr[{sti, stj}].push_back({abs(sti - i2) + abs(stj - j2), {i2, j2}});
        gr[{i2, j2}].push_back({abs(sti - i2) + abs(stj - j2), {sti, stj}});

        gr[{ti, tj}].push_back({abs(ti - i2) + abs(tj - j2), {i2, j2}});
        gr[{i2, j2}].push_back({abs(ti - i2) + abs(tj - j2), {ti, tj}});

        // Edge between (i1, j1) --> (i2, j2) .. Either Special Edge or NORMAL ??
        gr[{i1, j1}].push_back({min(c, abs(i1 - i2) + abs(j1 - j2)), {i2, j2}});


        // With all the other special Edges

        for(int j=i+1; j < arr.size() ; j++){

            int i3 = arr[j][0] , j3 = arr[j][1] , i4 = arr[j][2] , j4 = arr[j][3];

            gr[{i3, j3}].push_back({abs(i3 - i1) + abs(j3 - j1), {i1, j1}});
            gr[{i1, j1}].push_back({abs(i3 - i1) + abs(j3 - j1), {i3, j3}});

            gr[{i4, j4}].push_back({abs(i4 - i1) + abs(j4 - j1), {i1, j1}});
            gr[{i1, j1}].push_back({abs(i4 - i1) + abs(j4 - j1), {i4, j4}});

            gr[{i3, j3}].push_back({abs(i3 - i2) + abs(j3 - j2), {i2, j2}});
            gr[{i2, j2}].push_back({abs(i3 - i2) + abs(j3 - j2), {i3, j3}});

            gr[{i4, j4}].push_back({abs(i4 - i2) + abs(j4 - j2), {i2, j2}});
            gr[{i2, j2}].push_back({abs(i4 - i2) + abs(j4 - j2), {i4, j4}});


        }


    }
    

    // DIJKSTRA -------------------------------->>
    
    map<pair<int,int>, int> visited;
    map<pair<int,int>, int> dis;

    priority_queue< pair<int, pair<int, int>> , vector<pair<int,pair<int,int>>> , greater< pair<int, pair<int,int>>> > pq;

    pq.push({0, {sti, stj}});

    while(!pq.empty()){

        auto best = pq.top();
        pq.pop();

        int d = best.first;
        auto cord = best.second;

        if(visited[cord] == 1) continue;

        visited[cord] = 1;
        dis[cord] = d;

        for(auto ch : gr[cord]){

            if(visited[ch.second] == 0){
                pq.push({d + ch.first , ch.second});
            }

        }

    }

    return dis[{ti, tj}];


}


};


// int main(){

//     ios::sync_with_stdio(false); cin.tie(NULL);

//     // Your code here
    
    

//     return 0;
// }

