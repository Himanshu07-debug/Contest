string getSmallestString(string s, int k) {
    
    if(k == 0) return s;

    for(int i = 0;i<s.size() && k > 0;i++){

        int t = min(s[i] - 'a', ('z' - s[i]) + 1);

        if(t <= k){
            s[i] = 'a';
            k -= t;
        }
        else{
            int c1 = ((s[i] - 'a') + k)%26;
            int c2 = ((s[i] - 'a') - k)%26;
            if(c2 < 0) c2 += 26;

            if(c1 <= c2) s[i] = char('a' + c1);
            else s[i] = char('a' + c2);

            k = 0;
        }

    }

    return s;
}