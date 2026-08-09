class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector < bool > m(matrix.size(),false);
        vector < bool > n(matrix[0].size(),false);
        for (int i = 0 ; i < matrix.size() ; i++)
        {
            for (int j = 0 ; j<matrix[0].size() ; j++)
            {
                if(matrix[i][j]==0)
                {
                    m[i] = true;
                    n[j] = true;
                }
            }
        }
        for (int i = 0 ; i < matrix.size() ; i ++)
        {
            for (int j =0 ; j< matrix[0].size();j++)
            {
                if(m[i] || n[j])
                matrix[i][j]=0;
            }
        }
        

    }
};