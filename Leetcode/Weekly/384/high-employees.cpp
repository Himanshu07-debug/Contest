// You are given a 2D 0-indexed array of strings, access_times, with size n. For each i where 0 <= i <= n - 1, access_times[i][0] represents 
// the name of an employee, and access_times[i][1] represents the access time of that employee. All entries in access_times are within the same 
// day.

// The access time is represented as four digits using a 24-hour time format, for example, "0800" or "2250".
// An employee is said to be high-access if he has accessed the system three or more times within a one-hour period.
// Times with exactly one hour of difference are not considered part of the same one-hour period. For example, "0815" and "0915" are not part 
// of the same one-hour period.

// Access times at the start and end of the day are not counted within the same one-hour period. For example, "0005" and "2350" are not part 
// of the same one-hour period.

// Return a list that contains the names of high-access employees with any order you want.


// Input: access_times = [["a","0549"],["b","0457"],["a","0532"],["a","0621"],["b","0540"]]
// Output: ["a"]
// Explanation: "a" has three access times in the one-hour period of [05:32, 06:31] which are 05:32, 05:49, and 06:21.
// But "b" does not have more than two access times at all.
// So the answer is ["a"].


// Constraints:

// 1 <= access_times.length <= 100
// access_times[i].length == 2
// 1 <= access_times[i][0].length <= 10
// access_times[i][0] consists only of English small letters.
// access_times[i][1].length == 4
// access_times[i][1] is in 24-hour time format.
// access_times[i][1] consists only of '0' to '9'.


// LOGIC ------------------------------------------------>>

// first of all, yeah string ka diff kaise manage kronge.. always takes a common way.. its time.. do it in minutes.. or sec.. and compare the 
// integers..

// sort krdo... 
// now saare ch ko starting pt leke loop chalao baaki same ch pe, agar len >= 3 rhi within time diff 59... haa 3 baar same hour me... add to list

// O(n^2)  --> sabko starting maan rhe ho


// BETTER -->

// pure same character ka range nikal lo i.e subarray ka sorted hai.. to adjacent rhnge hi and then 2 pointers krdo -> longest subarray with
// diff <= 59..

// agar len >= 3, --> add

// O(nlogn) --> sorting and then range nikalne ke liye O(n) loop lagega --> har ek range me traverse O(2*n) times (2 pointers) .. O(3*n)


 bool possible(string s1, string s2){

        int min1 = stoi(s1.substr(0, 2))*60 + stoi(s1.substr(2));
        int min2 = stoi(s2.substr(0, 2))*60 + stoi(s2.substr(2));

        if(min1 - min2 >= 60) return true;
        else return false;

    }

    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        sort(access_times.begin(), access_times.end(), [](vector<string> a, vector<string> b){
            if(a[0] == b[0]) return a[1] < b[1];
            
            return a[0] < b[0];

        });

        int j = 0;

        vector<string> ans;

        while(j < access_times.size()){

            int i = j;

            while(j < access_times.size() && access_times[j][0] == access_times[i][0]) j++;

            int k = i, en = j - 1;
            int len = 0;

            while(k <= en){

                while(k <= en && possible(access_times[k][1], access_times[i][1])){
                    i++;
                }

                
                len = max(len,k - i + 1);

                if(len >= 3){
                    ans.push_back(access_times[k][0]);
                    break;
                }

                k++;

            }

        }

        return ans;
    }


// pura naive kar diye.. 2 pointers ke liye
// things to note --> lambda function dekho..
// time string ka conversion minutes me dekho...


// BEST ------------------->>

// O(1000*n)

// ek dinn me max 1441 minutes hi hote hai..

// map me add krdo each ch ko key leke uske log
// Har ek vector me traverse kro.. and diff array ka concept lagao...
// for t , t + 60 ko subtract kro

int string_to_int(string s){
    int val=0;
    for(int i=0;i<s.length();i++) val = val*10 + (s[i]-'0');
    
    return val;
}

vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
    map<string, vector<int>> times;
    for(vector<string> v : access_times){
        string s=v[1];
        
        int minutes = string_to_int(s.substr(0,2))*60 + string_to_int(s.substr(2));
        times[v[0]].push_back(minutes);
    }
    
    vector<string> ans;
    for(auto it=times.begin();it!=times.end();it++){
        string ch = it->first;
        vector<int> time = it->second;
        
        vector<int> sweep(1441,0);
        for(int t : time){
            // contribution of each access for next 59 minutes
            sweep[t]++;
            if(t+60 < 1441) sweep[t+60]--;
        }
        
        // check for at least 3 overlapping access times
        int c=0;
        for(int i=0;i<1441;i++){
            c += sweep[i];
            
            if(c>=3){
                ans.push_back(ch);
                break;
            }
        }
    }
    
    return ans;
}