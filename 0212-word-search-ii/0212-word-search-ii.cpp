class Solution {
public:

    struct TrieNode {
        TrieNode* children[26];
        string word;

        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            word = "";
        }
    };

    TrieNode* root = new TrieNode();

    void insert(string word) {
        TrieNode* node = root;

        for (char c : word) {
            int index = c - 'a';

            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }

            node = node->children[index];
        }

        node->word = word;
    }

    int rows;
    int cols;

    vector<string> result;

    void dfs(vector<vector<char>>& board,
             int row,
             int col,
             TrieNode* node) {

        // Boundary check
        if (row < 0 || row >= rows ||
            col < 0 || col >= cols) {
            return;
        }

        // Already visited
        if (board[row][col] == '#') {
            return;
        }

        char c = board[row][col];

        int index = c - 'a';

        // Character does not exist in Trie
        if (node->children[index] == nullptr) {
            return;
        }

        node = node->children[index];

        // Complete word found
        if (node->word != "") {
            result.push_back(node->word);

            // Prevent finding same word again
            node->word = "";
        }

        // Mark current cell as visited
        board[row][col] = '#';

        // Move down
        dfs(board, row + 1, col, node);

        // Move up
        dfs(board, row - 1, col, node);

        // Move right
        dfs(board, row, col + 1, node);

        // Move left
        dfs(board, row, col - 1, node);

        // Undo / backtrack
        board[row][col] = c;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        rows = board.size();
        cols = board[0].size();

        // Put all words into Trie
        for (string word : words) {
            insert(word);
        }

        // Start DFS from every cell
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dfs(board, i, j, root);
            }
        }

        return result;
    }
};