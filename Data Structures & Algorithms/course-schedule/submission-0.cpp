class Solution {
   public:
    bool check(int i, int n, vector<vector<int>>& pre, vector<bool>& vis,
               vector<bool>& retracepath) {
        vis[i] = true;
        retracepath[i] = true;

        for (int j = 0; j < pre.size(); j++) {
            int u = pre[j][1];
            int v = pre[j][0];

            if (i == u) {
                // Wrong
                // if(!vis[i]){

                // Correct
                if (!vis[v]) {
                    if (check(v, n, pre, vis, retracepath)) {
                        return true;
                    }
                }

                else if (retracepath[v]) {
                    return true;
                }
            }
        }

        retracepath[i] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<bool> vis(numCourses, false);
        vector<bool> retracepath(numCourses, false);

        int n = numCourses;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                // Wrong
                // check(i, n, pre, vis, retracepath);

                // Correct
                if (check(i, n, pre, vis, retracepath)) {
                    return false;
                }
            }
        }

        // Missing
        return true;
    }
};
