class Solution {
public:
int check(vector<vector<int>>&dp,string &text1,string &text2,int n,int m){

    if(n<0 || m<0){
        return 0;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    if(text1[n]==text2[m]){
      return dp[n][m]=1+check(dp,text1,text2,n-1,m-1);
    }
    else{
        return dp[n][m]=max(check(dp,text1,text2,n-1,m),check(dp,text1,text2,n,m-1));
    }
}
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return check(dp,text1,text2,n-1,m-1);
    }
};
