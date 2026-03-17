class Solution {
private:
    void dfs(vector<vector<int>>& mat, int i, int j, int newColor, int currColor) {
        if (mat[i][j] != currColor || mat[i][j] == newColor) return;
        mat[i][j] = newColor;

        if (i >= 1) dfs(mat, i-1, j, newColor, currColor);
        if (j >= 1) dfs(mat, i, j-1, newColor, currColor);
        if (i < mat.size()-1) dfs(mat, i+1, j, newColor, currColor);
        if (j < mat[0].size()-1) dfs(mat, i, j+1, newColor, currColor);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};