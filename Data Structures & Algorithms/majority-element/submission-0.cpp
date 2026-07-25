class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i : nums){
            mp[i]++;
        }
        for(auto [key,value] : mp){
            if(value > nums.size()/2){
                return key;
            }
        }
    }
};