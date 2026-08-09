class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int i, j;
        for(i = 0; i < r; i++)
        {
            set<int> temp;
            for(j = 0; j < c; j++)
                temp.insert(matrix[i][j]);

            if(temp.size() != r)
                return false;
        }
        
        for(i = 0; i < c; i++)
        {
            set<int> temp;
            for(j = 0; j < r; j++)
                temp.insert(matrix[j][i]);

            if(temp.size() != r)
                return false;    
        }
        return true;
    }
};