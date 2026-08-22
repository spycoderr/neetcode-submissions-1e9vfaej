class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] = i;
        }
        // map mai abhi nums[i] : i ka bngya hoga 

        for(int i = 0; i < nums.size(); i++){
            int temp = target - nums[i];
            for(auto [key,value] : mp){
                if(mp.find(temp) != mp.end() && i != mp[temp]){
                    return {i,mp[temp]};
                }
            }
        }

        return {-1,-1};
    }
};
