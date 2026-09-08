class Solution {
public:
    void dfs(vector<vector<int>>& image,  vector<vector<int>>& ans, int row, int col, int color, int prevColor)
    {
        ans[row][col] = color;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        for(int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && nrow < image.size() && ncol >= 0 && ncol < image[0].size() && ans[nrow][ncol] != color && image[nrow][ncol] == prevColor)
                dfs(image, ans, nrow, ncol, color, prevColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int prevColor = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(image, ans, sr, sc, color, prevColor);

        return ans;
    }
};