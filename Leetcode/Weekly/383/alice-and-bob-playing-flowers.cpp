// Alice and Bob are playing a turn-based game on a circular field surrounded by flowers. The circle represents the field, and there are x flowers 
// in the clockwise direction between Alice and Bob, and y flowers in the anti-clockwise direction between them.

// The game proceeds as follows:
// Alice takes the first turn.
// In each turn, a player must choose either the clockwise or anti-clockwise direction and pick one flower from that side.
// At the end of the turn, if there are no flowers left at all, the current player captures their opponent and wins the game.


// Given two integers, n and m, the task is to compute the number of possible pairs (x, y) that satisfy the conditions:

// Alice must win the game according to the described rules.
// The number of flowers x in the clockwise direction must be in the range [1,n].
// The number of flowers y in the anti-clockwise direction must be in the range [1,m].

// Return the number of possible pairs (x, y) that satisfy the conditions mentioned in the statement.

// Input: n = 3, m = 2
// Output: 3
// Explanation: The following pairs satisfy conditions described in the statement: (1,2), (3,2), (2,1).

// 1 <= n, m <= 10^5


// LOGIC ----------------------------->>

// one thing is very clear --> if x + y is odd, then only Alice can Win

// x + y ==> odd
// Math --> even + odd = odd  ,,,,  odd + even = odd

// just find all the even count of x and y side...
// then we can make pairs...

long long flowerGame(int n, int m) {

    long long oddx=0, eveny=0, evenx=0, oddy=0;
    
    evenx = n/2;
    oddx = n%2 == 0 ? evenx : evenx+1;

    eveny = m/2;
    oddy = m%2 == 0 ? eveny : eveny+1;
    
    return oddx*eveny + evenx*oddy;
    
}