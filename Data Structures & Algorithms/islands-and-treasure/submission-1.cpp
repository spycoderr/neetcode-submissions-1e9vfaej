class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& rooms) {
        int row = rooms.size();
        int col = rooms[0].size();

        queue<pair<int, int>> q;

        // Step 1: Saare gates queue mein daalo
        // ye to normal hai
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        // Step 2: Four directions
        // this is for four directional calls
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        // Step 3: BFS
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                //this is for base cases out of bound or already visited or water 
                if (nr < 0 || nc < 0 || nr >= row || nc >= col || rooms[nr][nc] != INT_MAX) {
                    continue;
                }

                // Step 4: Distance update
                // MAIN BFS STEP
                rooms[nr][nc] = rooms[r][c] + 1;

                q.push({nr, nc});
            }
        }
    }
};