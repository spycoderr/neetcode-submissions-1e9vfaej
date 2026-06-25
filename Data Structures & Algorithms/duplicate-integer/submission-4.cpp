class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> mapu;
        for (int i : nums) {
            if (mapu.count(i)) {
                return true;
            }
            mapu.insert(i);
        }
        return false;
    }
};