// You are given a 2D array points and a string s where, points[i] represents the coordinates of point i, and s[i] represents the tag of point i.

// A valid square is a square centered at the origin (0, 0), has edges parallel to the axes, and does not contain two points with the same tag.

// Return the maximum number of points contained in a valid square.

// Note:

// A point is considered to be inside the square if it lies on or within the square's boundaries.
// The side length of the square can be zero.

// Input: points = [[2,2],[-1,-2],[-4,4],[-3,1],[3,-3]], s = "abdca"
// Output: 2
// Explanation: The square of side length 4 covers two points points[0] and points[1].

// Constraints:

// 1 <= s.length, points.length <= 10^5
// points[i].length == 2
// -10^9 <= points[i][0], points[i][1] <= 10^9
// s.length == points.length
// points consists of distinct coordinates.
// s consists only of lowercase English letters.


// LOGIC --------------------------------------------->>


// Lets try to observe.. 
// If I make a square length of 1 from origin, let the no. points inside it is x
// If i make a square length of 2, let the no. of points inside it as x + 1 or x 
// If i make a square length of 3, I got the violation ... 
// now just say agar 4, 5 ka bhi bananya to violation rhnga hi...

// Monotonicity dikhi...
// Search space --> side length from origin..

// Lekin muje ans me max points chahiye, max length valid square nhi.. length ka search space .. why ??
// max length valid jo honga ussi me max points honge....

// last me max length ke liye points nikal lenge..

// O(nlogn) solution... will accepted

vector<vector<int>> ans;

bool poss(int m, string s){

    int cnt[26] = {0};

    for(int i=0;i<ans.size();i++){

        if(ans[i][0] >= -m && ans[i][0] <= m && ans[i][1] >= -m && ans[i][1] <= m){
            if(cnt[s[i] - 'a'] != 0) return false;
            cnt[s[i] - 'a'] = 1;
        } 

    }

    return true;

}

int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
    int l = 0, r = 1e9;

    ans = points;

    while(l < r){
        int m = (l + r + 1)/2;

        if(poss(m, s)){
            l = m;
        }
        else{
            r = m - 1;
        }

    }

    int c = 0;
    for(int i=0;i<ans.size();i++){

        if(ans[i][0] >= -l && ans[i][0] <= l && ans[i][1] >= -l && ans[i][1] <= l){
            c++;
        } 

    }

    return c;

}