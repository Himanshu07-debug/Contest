class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> pref(n, 0);

        pref[0] = nums[0];

        for(int i=1;i<n;i++) pref[i] = pref[i-1] + nums[i];

        long long ans = -1;

        for(int i=2;i<n;i++){

            if(nums[i] < pref[i - 1]){
                ans = max(ans, nums[i] + pref[i-1]);
            }

        }

        return ans;
    }
};