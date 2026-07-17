class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int yo=0;
        int ans=0;
        while(yo<k){
            ans=pq.top();
            pq.pop();
            yo++;
           
        }
        return ans;
    }
};
