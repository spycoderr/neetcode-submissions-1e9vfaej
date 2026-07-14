class Solution {
   public:
    int count = 0;

    void check(vector<int>& heights, int pass, int index) {
        int mini = pass;

        for (int i = index; i < heights.size(); i++) {
            if (heights[i] < heights[mini]) {
                mini = i;
            }
        }

        swap(heights[mini], heights[pass]);
    }

    int heightChecker(vector<int>& heights) {
        vector<int> original = heights;

        for (int i = 0; i < heights.size(); i++) {
            check(heights, i, i); 
        }

        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != original[i]) {
                count++;
            }
        }

        return count;
    }
};