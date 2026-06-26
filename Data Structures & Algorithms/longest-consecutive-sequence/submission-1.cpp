class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int countu = 1;
        int maxu = 1;

        for(int i = 0; i < nums.size()-1; i++) {

            if(nums[i] + 1 == nums[i+1]) {
                countu++;
            }
            else if(nums[i] == nums[i+1]) {
                continue;
            }
            else {
                countu = 1;
            }

            maxu = max(maxu, countu);
        }

        return maxu;
    }
};
