class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n= mat[0].size();
        vector<vector<int>>matrix (r, vector<int>(c));
        queue<int> q;

        if(m * n == r * c)
        {
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                    q.push(mat[i][j]);
            }
            for(int i = 0; i < r; i++)
            {
                for(int j = 0; j < c; j++)
                {
                    matrix[i][j] = q.front();
                    q.pop();
                }
            }
            return matrix;
        }
        else 
            return mat;
    }
};