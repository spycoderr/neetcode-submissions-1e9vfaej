class Solution {
   public:
    bool dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, int n, int m,
             int defrow[], int defcol[], string& word, int wordindex) {
        if (wordindex == word.size() - 1) {
            return true;
        }

        visited[i][j] = 1;

        for (int k = 0; k < 4; k++) {
            int newrow = i + defrow[k];
            int newcol = j + defcol[k];

            if (newrow >= 0 && newcol >= 0 && newrow < n && newcol < m &&
                !visited[newrow][newcol] && board[newrow][newcol] == word[wordindex + 1]) {
                if (dfs(board, visited, newrow, newcol, n, m, defrow, defcol, word,
                        wordindex + 1)) {
                    return true;
                }
            }
        }

        visited[i][j] = 0;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        int defrow[] = {-1, 0, 1, 0};
        int defcol[] = {0, -1, 0, 1};

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, visited, i, j, n, m, defrow, defcol, word, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
