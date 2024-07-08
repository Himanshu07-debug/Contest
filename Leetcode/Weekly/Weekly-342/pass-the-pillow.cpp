// There are n people standing in a line labeled from 1 to n. The first person in the line is holding a pillow initially. Every second, 
// the person holding the pillow passes it to the next person standing in the line. Once the pillow reaches the end of the line, the direction 
// changes, and people continue passing the pillow in the opposite direction.

// For example, once the pillow reaches the nth person they pass it to the n - 1th person, then to the n - 2th person and so on.
// Given the two positive integers n and time, return the index of the person holding the pillow after time seconds.

// Input: n = 4, time = 5
// Output: 2
// Explanation: People pass the pillow in the following way: 1 -> 2 -> 3 -> 4 -> 3 -> 2.
// After five seconds, the 2nd person is holding the pillow.


// famous pattern question --> asked in many way ..


int passThePillow(int n, int time) {

    int rounds = time/(n-1);

    // time -= (n-1)*x;  --> no need of this

    if(x&1){
        return n - time%(n-1);
    }

    else{
        return 1 + time%(n-1);   // after time seconds btana hai --> +1
    }
}

