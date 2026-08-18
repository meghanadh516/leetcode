class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {

        int m = img.size();
        int n = img[0].size();

        vector<vector<int>> result(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int sum = 0;
                int count = 0;

                // Check the 3 x 3 area around img[i][j]
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {

                        // Make sure we are inside the matrix
                        if (x >= 0 && x < m && y >= 0 && y < n) {
                            sum += img[x][y];
                            count++;
                        }
                    }
                }

                result[i][j] = sum / count;
            }
        }

        return result;
    }
};