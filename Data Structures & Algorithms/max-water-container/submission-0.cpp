class Solution {
public:
    int maxArea(vector<int>& heights) {

        int left = 0;
        int right = heights.size() - 1;
        int maxu = 0;

        while(left < right){

            int high = min(heights[left], heights[right]);

            int area = high * (right - left);

            maxu = max(maxu, area);

            if(heights[left] < heights[right]){
                left++;
            }
            else{
                right--;
            }
        }

        return maxu;
    }
};