// LINK --> https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/


#include<bits/stdc++.h>
using namespace std;

int areaOfMaxDiagonal(vector<vector<int>>& arr) {
        
    int mx = 0;
    int ar = 0;

    int c = 0;

    for(auto x: arr){

        int a = x[0] , b = x[1];

        if((a*a + b*b) > mx){
            mx = (a*a + b*b);
            ar = a*b;
        }
        else if((a*a + b*b) == mx){
            if(a*b > ar) ar = a*b;
        }
    }

    return ar;
        
}


int main(){

    return 0;

}