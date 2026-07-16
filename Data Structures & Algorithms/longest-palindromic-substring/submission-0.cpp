class Solution {
public:
    string ans = "";

    void check(int i, int j, string &s) {

        while(i >= 0 && j < s.size() && s[i] == s[j]) {

            if(j - i + 1 > ans.size()) {
                ans = s.substr(i, j - i + 1);
            }

            i--;
            j++;
        }
    }

    string longestPalindrome(string s) {

        for(int i = 0; i < s.size(); i++) {

            check(i, i, s);     
            check(i, i + 1, s); 
        }

        return ans;
    }
};