class Solution {
   public:
    bool iscycle(int src, vector<bool>& vis, vector<bool>& retracepath, vector<vector<int>>& pre) {
        vis[src] = true;
        retracepath[src] = true;

        for (int i = 0; i < pre.size(); i++) {
            int u = pre[i][1];  // prerequisite
            int v = pre[i][0];  // course

            if (src == u) {
                if (!vis[v]) {
                    if (iscycle(v, vis, retracepath, pre)) return true;
                } else if (retracepath[v]) {
                    return true;
                }
            }
        }

        retracepath[src] = false;
        return false;
    }

    void topo(int src, vector<bool>& vis, vector<vector<int>>& pre, stack<int>& s) {
        vis[src] = true;

        for (int i = 0; i < pre.size(); i++) {
            int u = pre[i][1];
            int v = pre[i][0];

            if (src == u) {
                if (!vis[v]) {
                    topo(v, vis, pre, s);
                }
            }
        }

        s.push(src);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        int n = numCourses;

        vector<int> ans;
        vector<bool> vis(n, false);
        vector<bool> retracepath(n, false);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (iscycle(i, vis, retracepath, pre)) return ans;
            }
        }

        vis.assign(n, false);

        stack<int> s;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                topo(i, vis, pre, s);
            }
        }

        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};
