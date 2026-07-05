class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>hehe;
        int n = position.size();
        vector<double> ans(n, 0);
    
        int fleet=0;
        for(int i=0;i<position.size();i++){
            hehe.push_back({position[i],speed[i]});
        }
        sort(hehe.begin(),hehe.end());
        for(int i=0;i<position.size();i++){
            ans[i] = (double)(target - hehe[i].first) / hehe[i].second;
        }
        double last_time=0;
        for(int i=ans.size()-1;i>=0;i--){
            if(ans[i]>last_time){
                fleet++;
                last_time=ans[i];
            }
        }
        return fleet;
    }
};