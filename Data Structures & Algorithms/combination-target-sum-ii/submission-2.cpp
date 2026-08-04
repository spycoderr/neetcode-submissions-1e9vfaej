class Solution {
   public:
    void combination(int target, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans,
                     int index, int n) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (target < 0 || index >= n) {
            return;
        }

        int next = index + 1;
        while (next < n && nums[next] == nums[index]) next++;

        combination(target, nums, temp, ans, next, n);
        temp.push_back(nums[index]);
        combination(target - nums[index], nums, temp, ans, index + 1, n);
        temp.pop_back();
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<int> temp;
        vector<vector<int>> ans;
        int n = nums.size();

        combination(target, nums, temp, ans, 0, n);
        return ans;
    }
};
