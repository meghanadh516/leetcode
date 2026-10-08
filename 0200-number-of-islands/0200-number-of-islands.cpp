class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {

        // Check boundaries
        if (i < 0 || i >= grid.size() ||
            j < 0 || j >= grid[0].size() ||
            grid[i][j] == '0') {
            return;
        }

        // Mark this land as visited
        grid[i][j] = '0';

        // Visit up
        dfs(grid, i - 1, j);

        // Visit down
        dfs(grid, i + 1, j);

        // Visit left
        dfs(grid, i, j - 1);

        // Visit right
        dfs(grid, i, j + 1);
    }

    int numIslands(vector<vector<char>>& grid) {

        int count = 0;

        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (grid[i][j] == '1') {

                    // Found a new island
                    count++;

                    // Explore the complete island
                    dfs(grid, i, j);
                }
            }
        }

        return count;
    }
};