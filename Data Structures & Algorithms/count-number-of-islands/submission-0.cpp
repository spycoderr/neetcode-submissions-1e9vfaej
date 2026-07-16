class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &visited, vector<vector<char>>& grid, int m, int n){
        if(i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || grid[i][j] != '1'){
            return;
        }

        visited[i][j] = 1;

        dfs(i,j-1,visited,grid,m,n); // left
        dfs(i-1,j,visited,grid,m,n); // top
        dfs(i,j+1,visited,grid,m,n); // right
        dfs(i+1,j,visited,grid,m,n); // bottom

    
    }

    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int count = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    dfs(i,j,visited,grid,m,n);
                    count++;
                }
            }
        }

        return count;

    }
};