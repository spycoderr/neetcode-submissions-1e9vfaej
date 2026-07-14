class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> s;

        for (int i = 0; i < a.size(); i++) {

            if (a[i] > 0) {
                s.push(a[i]);
            } 
            else {
                while (!s.empty() && s.top() > 0 && s.top() < abs(a[i])) {
                    s.pop();
                }

                if (s.empty() || s.top() < 0) {
                    s.push(a[i]);
                }
                else if (s.top() == abs(a[i])) {
                    s.pop();
                }
                // else: s.top() > abs(a[i])
                // current asteroid destroy ho jayega, kuch mat karo
            }
        }

        vector<int> ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};