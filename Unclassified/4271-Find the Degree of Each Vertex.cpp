class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector <int> ans(matrix.size(), 0);

        for(int i = 0; i < matrix.size(); i++)
        {
            int count = 0;
            for(int j = 0; j < matrix.size(); j++)
            {
                if(matrix[i][j] == 1)
                {
                    count++;
                }
            } 
            ans[i] = count;   
        }
        return ans;
    }
};