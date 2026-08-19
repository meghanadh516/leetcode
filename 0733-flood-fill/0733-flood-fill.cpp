class Solution {
public:
    
    void dfs(vector<vector<int>>& image, int r, int c, int originalcolor, int newcolor) {

        int rows = image.size();
        int col = image[0].size();

        if( r <0 || r>= rows || c< 0 || c>= col)
        return;

        if(image[r][c] != originalcolor)
        return;

        image[r][c] = newcolor;

        dfs(image, r-1, c, originalcolor, newcolor);
        dfs(image, r+1, c, originalcolor, newcolor);
        dfs(image, r, c-1, originalcolor, newcolor);
        dfs(image, r, c+1, originalcolor, newcolor);
    };

    vector<vector<int>> floodFill(vector<vector<int>> image, int sr, int sc, int color) {

        int originalcolor = image[sr][sc];

        if(originalcolor == color)
        return image;

        dfs(image, sr,sc, originalcolor, color);
        return image;

    }
};