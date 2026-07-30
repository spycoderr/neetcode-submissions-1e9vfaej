class Solution {
public:

    int solve(string &text1, string &text2, vector<vector<int>>&dp, int m, int n){

        if(m < 0 || n < 0){
            return 0;
        }

        if(dp[m][n] != -1){
            return dp[m][n];
        }

        if(text1[m] == text2[n]){
            return dp[m][n] = 1 + solve(text1,text2,dp,m-1,n-1);
        } else{
            return dp[m][n] = max(solve(text1,text2,dp,m,n-1),solve(text1,text2,dp,m-1,n));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(text1,text2,dp,m-1,n-1);
    }
};
