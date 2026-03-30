class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int t5=0;
        int t10=0;
        int t20=0;
        int i=0;
        int n=bills.size();
        while(i<n){
            if(bills[i]==5){
                t5=t5+1;
                i++;
            }
            else if(bills[i]==10){
                if(t5>=1){
                    t10++;
                    t5--;
                    i++;
                } else {
                    return false;
                }
            }
            else if(bills[i]==20){
                if(t5>=1 && t10>=1){
                    t10--;
                    t5--;
                    t20++;
                    i++;
                }
                else if(t5>=3){
                    t5=t5-3;
                    t20++;
                    i++;
                } else {
                    return false;
                }
            }
        }
        return i == n;
    }
};