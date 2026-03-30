class Solution {
public:

    int knapsack(int index, vector<int>& profit, vector<int>& weight, int capacity,vector<vector<int>>& dp){
        if(index < 0 || capacity <= 0){
            return 0;
        }

        if(dp[index][capacity] != -1){
            return dp[index][capacity];
        }
        int take = 0;

        if(weight[index] <= capacity){
          take = profit[index] + knapsack(index-1,profit,weight,capacity - weight[index],dp);
        }

        int not_take = knapsack(index-1,profit,weight,capacity,dp);

        return dp[index][capacity] = max(take,not_take);
    }

    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {

        int n = profit.size();
        int index = n-1;
        vector<vector<int>>dp(n,vector<int>(capacity+1,-1));

        return knapsack(index,profit,weight,capacity,dp);
    }
};
