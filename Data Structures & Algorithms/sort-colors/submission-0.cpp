class Solution {
public:
    void sortColors(vector<int>& nums) {
        // optimized way
        // dutch national flag
        // so basically we have to divide array in 4parts ya 3 maanlo
        // agar 0 mila array ke start me bhejdo , agar 1 mila vhi rehne do and 2 mila to 
        // array ke end me bhejdo 

        // sirf swappings and three pointers ka use krna hai and ek for loop
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[mid] == 0){
                // array ke start me bhejo
                swap(nums[low],nums[mid]);
                low++;
                mid++;
                // aage bhi to move krna hai na swap krne ke baad indexes ko
            }
            else if(nums[mid] == 1){
                // vahi pde rehne do
                mid++;
            } 
            else{
                // nums[mid] == 2;
                // end me bhej do
                swap(nums[mid],nums[high]);
                high--; // very important 
            }
        }
    }
};