class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size(); // row
        int n = grid[0].size(); // coloumn

        vector<vector<bool>> visited(m, vector<bool>(n,false));

        // 0 empty // 1 fresh // 2 rotten

        int ans = 0;

        queue<pair<pair<int,int>,int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    visited[i][j] = true;
                }
            }
        }

        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            q.pop();

            ans = max(ans,time);

            // 4 condition for left right top bottom 

            // top i-1,j
            if(i-1 >= 0 && !visited[i-1][j] && grid[i-1][j] == 1){
                // rot krdenge and push kr denge
                grid[i-1][j] = 2;
                visited[i-1][j] = true;
                q.push({{i-1,j},time+1});
            }
            // right i,j+1
            if(j+1 < n && !visited[i][j+1] && grid[i][j+1] == 1){
                // rot krdenge and push kr denge
                grid[i][j+1] = 2;
                visited[i][j+1] = true;
                q.push({{i,j+1},time+1});
            }
            // bottom i+1,j
            if(i+1 < m && !visited[i+1][j] && grid[i+1][j] == 1){
                // rot krdenge and push kr denge
                grid[i+1][j] = 2;
                visited[i+1][j] = true;
                q.push({{i+1,j},time+1});
            }
            // left i,j-1
            if(j-1 >= 0 && !visited[i][j-1] && grid[i][j-1] == 1){
                // rot krdenge and push kr denge
                grid[i][j-1] = 2;
                visited[i][j-1] = true;
                q.push({{i,j-1},time+1});
            }

        }

        // ye miss hogya tha
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return ans;
    }
};
