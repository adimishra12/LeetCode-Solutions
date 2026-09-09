class Solution {
public:
    int m, n;
    vector<vector<int>> t;
    int dfs(vector<vector<int>>& matrix, int row, int col)
    {
        int delr[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        if(t[row][col] != 0)
            return t[row][col];

        int ans = 1;
        for(int i = 0; i < 4; i++)    
        {
            int newrow = row + delr[i];
            int newcol = col + delcol[i];
            if(newrow < 0 || newrow >= m || newcol < 0 || newcol >= n || matrix[newrow][newcol] <= matrix[row][col])
                continue;

            ans = max(ans, dfs(matrix, newrow, newcol) + 1);    
        }
        return t[row][col] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int ans = 0;
        t.resize(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
                ans = max(ans, dfs(matrix, i, j));
        }
        return ans;
    }
};