class Solution {
   public:
    void combination(int target, vector<int>& nums, vector<int> temp, vector<vector<int>>& ans,
                     int index, int n) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (target < 0 || index >= n) {
            return;
        }

        combination(target, nums, temp, ans, index + 1, n);
        temp.push_back(nums[index]);
        combination(target - nums[index], nums, temp, ans, index, n);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        // add krte rho and kabhi bhi target < 0 hogya matlab
        // return krjao and = 0 hogya then pushback in answer

        vector<int> temp;
        vector<vector<int>> ans;
        int n = nums.size();

        combination(target, nums, temp, ans, 0, n);
        return ans;
    }
};
