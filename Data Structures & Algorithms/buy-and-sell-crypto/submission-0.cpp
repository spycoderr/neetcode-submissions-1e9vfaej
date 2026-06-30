class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int profit = 0;
        int maxu = 0;

        while(right < prices.size() && left < prices.size()){
            profit = prices[right] - prices[left];

            if(profit < 0){
                left = right;
                right++;
            }

            else{
                maxu = max(maxu,profit);
                right++;
            }
        }

        return maxu;
    }
};
