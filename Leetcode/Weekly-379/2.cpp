// LINK -> https://leetcode.com/problems/minimum-moves-to-capture-the-queen/


// In worst case there will be atmost 2 moves that will be performed by rook to kill the Queen 

// If the Queen and the Rook is on the Same row or same column, rook can kill the Queen in one move... 

// But what if Bishop is in the middle of the Rook and Queen, then in 1 move, First Bishop has to be moved from the row to some other row and then
// rook will kill the Queen

// Similar case, when Queen is at the same Diagonal of the Bishop but Rook is at the middle, we had to first move Rook in 1 move and here also 2 
// moves will required

// How to know the between the Rook and the Queen in a row, Bishop is there ??
// Consider the x-axis, if Bishop (c,d) is at the middle then ( d - b ) -> +ve and (d - f) -> -ve and their product ( d - b ) * (d - f) -> -ve
//  If columns are same, we can check at Y-axis with X co-ordinites

// In case of Bishop, 
// Same Diagonal Condition for Bishop and Queen --> abs(c - e) == abs(d - f) .. [ becz if x diff == y diff , then pts are in Diagonal in GRID ]
// To check rook is at the middle or not if it is at the Same diagonal -> Consider x-axis with Y co-ordinites .. ( b - f ) * (b - d) < 0


#include<bits/stdc++.h>
using namespace std;


int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {

    if(a == e || b == f){

        if(a == e && a == c && ((d - b) * (d - f)) < 0) return 2;
        if(b == f && b == d && ((c - a) * (c - e)) < 0) return 2;
        return 1; 

    }

    if(abs(c - e) == abs(d - f)){

        if(abs(c - a) == abs(d - b) && ((b - f) * (b - d)) < 0) return 2;
        return 1;

    }

    return 1;
        
}



int main(){

    return 0;

}