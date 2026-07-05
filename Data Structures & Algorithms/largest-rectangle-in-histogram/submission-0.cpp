class Solution {
   public:
    int area = 0;
    int maxu = 0;

    vector<int> left(vector<int>& heights) {
        stack<pair<int, int>> s;
        vector<int> ans;

        for (int i = 0; i < heights.size(); i++) {
            while (!s.empty() && s.top().second >= heights[i]) {
                s.pop();
            }

            if (s.empty()) {
                ans.push_back(-1);
            } else {
                ans.push_back(s.top().first);
            }

            s.push({i, heights[i]});
        }

        return ans;
    }

    vector<int> right(vector<int>& heights) {
        stack<pair<int, int>> s;
        vector<int> ans;

        for (int i = heights.size() - 1; i >= 0; i--) {
            while (!s.empty() && s.top().second >= heights[i]) {
                s.pop();
            }

            if (s.empty()) {
                ans.push_back(heights.size());
            } else {
                ans.push_back(s.top().first);
            }

            s.push({i, heights[i]});
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> le = left(heights);
        vector<int> re = right(heights);

        for (int i = 0; i < heights.size(); i++) {
            area = (re[i] - le[i] - 1) * heights[i];
            maxu = max(maxu, area);
        }

        return maxu;
    }
};
