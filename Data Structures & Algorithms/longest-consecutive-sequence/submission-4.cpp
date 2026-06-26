class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int count = 1;
        int maxCount = 0;

        for (int i = 0; i < (int)nums.size()-1; i++) {

            if (nums[i + 1] == nums[i]) {
                continue;
            }

            if (nums[i + 1] == (nums[i] + 1)) {
                // cout << count;
                count++;
            } 
            else {
                maxCount = max(maxCount, count);
                // cout << maxCount << " ";
                count = 1;
            }
        }

        return max(maxCount,count);
    }
};
