class Solution {
   public:
    int check(vector<int>& nums, vector<int>& dp, int n) {
        if (n < 0) return 0;

        if (dp[n] != -1) return dp[n];

        int take = nums[n] + check(nums, dp, n - 2);
        int notTake = check(nums, dp, n - 1);

        return dp[n] = max(take, notTake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        vector<int> first, second;

      
        for (int i = 0; i < n - 1; i++) first.push_back(nums[i]);

       
        for (int i = 1; i < n; i++) second.push_back(nums[i]);

        vector<int> dp1(first.size(), -1);
        vector<int> dp2(second.size(), -1);

        int ans1 = check(first, dp1, first.size() - 1);
        int ans2 = check(second, dp2, second.size() - 1);

        return max(ans1, ans2);
    }
};
