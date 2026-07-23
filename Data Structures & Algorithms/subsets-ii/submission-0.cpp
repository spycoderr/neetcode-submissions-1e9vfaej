class Solution {
public:
void check(vector<int>temp,vector<vector<int>>&ans,int index,vector<int>& nums){
    if(index==nums.size()){
            ans.push_back(temp);
        return;
    }
     temp.push_back(nums[index]);
    check(temp,ans,index+1,nums);
    temp.pop_back();
   while(index + 1 < nums.size() && nums[index]==nums[index+1]){
    index++;
   }
    check(temp,ans,index+1,nums);
   
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        vector<vector<int>>ans;
        int i=0;
        check(temp,ans,i,nums);
        return ans;
    }
};