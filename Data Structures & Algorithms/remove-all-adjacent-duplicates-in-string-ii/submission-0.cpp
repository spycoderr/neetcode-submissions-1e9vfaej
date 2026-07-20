class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<int,char>>hehe;
       
        
        for(auto ch:s){
            if(!hehe.empty() && hehe.top().second==ch){
                     hehe.top().first++;
            }
            else{
             hehe.push({1, ch});
            }
             if(hehe.top().first==k){
                hehe.pop();

            }
        }
        string ans="";
        while(!hehe.empty()){
            char c=hehe.top().second;
            int ch=hehe.top().first;
            hehe.pop();
           ans.append(ch,c);

        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};