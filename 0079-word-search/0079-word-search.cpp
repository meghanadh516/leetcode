class Solution {
public:

    bool dfs(vector<vector<char>>& board,
             string& word,
             int row,
             int col,
             int index) {

        // We found the complete word
        if (index == word.size()) {
            return true;
        }

        // Check boundaries
        if (row < 0 || row >= board.size() ||
            col < 0 || col >= board[0].size()) {
            return false;
        }

        // Current cell doesn't match
        if (board[row][col] != word[index]) {
            return false;
        }

        // Mark this cell as visited
        char temp = board[row][col];
        board[row][col] = '#';

        // Search in 4 directions
        bool found =
            dfs(board, word, row + 1, col, index + 1) ||
            dfs(board, word, row - 1, col, index + 1) ||
            dfs(board, word, row, col + 1, index + 1) ||
            dfs(board, word, row, col - 1, index + 1);

        // Undo / backtrack
        board[row][col] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int rows = board.size();
        int cols = board[0].size();

        // Try every cell as a starting point
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};