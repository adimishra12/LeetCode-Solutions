class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int t = 0, b = n - 1, l = 0, r = m - 1;
        vector<int> ans;

        while(r >= l && t <= b)
        {
            for(int i = l; i <= r; i++)
                ans.push_back(matrix[t][i]);
            t++;  

            for(int j = t; j <= b; j++)
                ans.push_back(matrix[j][r]);
            r--;

            if(t <= b)
            {
                for(int i = r; i >= l; i--)
                    ans.push_back(matrix[b][i]);
                b--;
            }

            if(l <= r)
            {   
                for(int i = b; i >= t; i--)
                    ans.push_back(matrix[i][l]);
                l++;      
            }
        } 
        return ans;
    }
};