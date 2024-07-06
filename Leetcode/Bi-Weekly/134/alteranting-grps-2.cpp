int numberOfAlternatingGroups(vector<int>& colors, int k) {

    vector<int> tmp = colors;

    int n = colors.size();

    for(int i=0;i<k - 1;i++){
        tmp.push_back(tmp[i]);
    }

    int x = tmp.size();

    int cnt = 0;
    int i = 0, j = 0;

    while(j < x && i < n){

        if(j - i + 1 < k){

            j++;

            if(j > 0 && tmp[j] == tmp[j-1]) i = j;

        }
        
        if(j - i + 1 == k){
            cnt++;
            i++;
        }

    }

    return cnt;
        
}