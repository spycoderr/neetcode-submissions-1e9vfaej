class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int maxu = 0;

        for (int left = 0; left < s.size(); left++) {
            unordered_set<char> seen;
            int count = 0;

            for (int right = left; right < s.size(); right++) {
                if (seen.count(s[right])) {
                    break;
                } else {
                    seen.insert(s[right]);
                    count++;
                }
            }

            maxu = max(maxu, count);
        }

        return maxu;
    }
};
