class Solution {
   public:
    int count = 0;
    void check(int i, int j, string s, int n) {
        while (i >= 0 && j < n && s[i] == s[j]) {
            count++;
            i--;
            j++;
        }
    }
    int countSubstrings(string s) {
        int n = s.size();

        for (int i = 0; i < n; i++) {
            check(i, i, s, n); 
            check(i, i + 1, s, n);
        }
        return count;
    }
};
