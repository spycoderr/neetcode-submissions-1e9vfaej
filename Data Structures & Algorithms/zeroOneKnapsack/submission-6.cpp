class Solution {
public:
int pro(vector<int>& profit, vector<int>& weight, int capacity,int size,vector<vector<int>>&dp){
    if(capacity<=0 || size<0){
        return 0;
    }
    if (dp[size][capacity]!=-1){
        return dp[size][capacity];
    }
    int take=0;
    int nottake=0;
    if(capacity>=weight[size]){
        take=profit[size]+pro(profit,weight,capacity-weight[size],size-1,dp);
    }
     nottake=pro(profit,weight,capacity,size-1,dp);
return dp[size][capacity]=max(take,nottake);
}
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        int n=profit.size();
        vector<vector<int>>dp(n,vector<int>(capacity + 1,-1));
        return pro(profit,weight,capacity,n - 1,dp);
    }
};