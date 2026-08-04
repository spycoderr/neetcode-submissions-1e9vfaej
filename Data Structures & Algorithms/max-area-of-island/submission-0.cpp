class Solution {
   public:
    int count = 0;
    int maxu = 0;

    void dfs(vector<vector<bool>>& vis, vector<vector<int>>& grid, int i, int j, int n, int m) {
        if (i < 0 || j >= m || i >= n || j < 0 || grid[i][j] == 0 || vis[i][j] == 1) {
            return;
        }

        vis[i][j] = 1;
        count++;
        dfs(vis, grid, i - 1, j, n, m);
        dfs(vis, grid, i + 1, j, n, m);
        dfs(vis, grid, i, j - 1, n, m);
        dfs(vis, grid, i, j + 1, n, m);
        
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    count = 0;
                    dfs(vis, grid, i, j, n, m);
                    maxu = max(maxu, count);
                }
            }
        }

        return maxu;
    }
};
