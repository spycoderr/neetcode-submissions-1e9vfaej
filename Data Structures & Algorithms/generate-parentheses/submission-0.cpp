class Solution {
   public:
    void combination(int open, int close, int n, string temp, vector<string>& ans) {
        if (open == n && close == n) {
            ans.push_back(temp);
            return;
        }

        if (open < n) {
            combination(open + 1, close, n, temp + '(', ans);
        }

        if (close < open) {
            combination(open, close + 1, n, temp + ')', ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        string temp = "";
        vector<string> ans;

        combination(0, 0, n, temp, ans);
        return ans;
    }
};
