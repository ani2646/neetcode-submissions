class Solution {
public:
    int m, n;
    vector<vector<int>> dirs = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    bool dfs(vector<vector<char>>& board,
             string& word,
             int i,
             int j,
             int ind) {

        if (ind == word.size())
            return true;

        if (i < 0 || i >= m || j < 0 || j >= n ||
            board[i][j] != word[ind])
            return false;

        char temp = board[i][j];
        board[i][j] = '#';   // mark visited

        for (auto& dir : dirs) {
            int ni = i + dir[0];
            int nj = j + dir[1];

            if (dfs(board, word, ni, nj, ind + 1)) {
                board[i][j] = temp; // backtrack before returning
                return true;
            }
        }

        board[i][j] = temp; // backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};