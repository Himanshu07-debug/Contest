 int minimumPushes(string word) {
    int cnt[26] = {0};

    for(char c : word) cnt[c - 'a']++;

    sort(cnt,cnt + 26, greater<int>());

    int ans = 0;
    int mul = 1;

    for(int i=0;i<26;i++){
        if(cnt[i] == 0) break;
        if(i >= 8*mul) mul++; 
        ans += cnt[i]*mul;
    }

    return ans;
}