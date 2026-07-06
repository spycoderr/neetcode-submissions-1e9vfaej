class Solution {
public:
    double findMedianSortedArrays(vector<int>& num1, vector<int>& num2) {
        int n=num1.size();
        int m=num2.size();
        int i=0;
        int j=0;
        vector<int>ans;
        while(i<n && j<m){
            if(num1[i]<num2[j]){
                ans.push_back(num1[i]);
                i++;
            }
             else if(num1[i]>num2[j]){
                ans.push_back(num2[j]);
                j++;
            }
            else {
                ans.push_back(num1[i]);
                i++;
            }
        }
        while(i<n){
            ans.push_back(num1[i]);
            i++;
        }
        while(j<m){
            ans.push_back(num2[j]);
            j++;
        }
        int sizu=ans.size();
        if(sizu%2!=0){
            return ans[sizu/2];
        }
        else {
            return (ans[sizu/2-1]+ans[sizu/2])/2.0;
        }
    }
};
