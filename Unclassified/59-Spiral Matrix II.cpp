class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++)
            ans.push_back(vector<int>(n));

        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int num = 1;

        while(top <= bottom && left <= right) 
        {

            for (int k = left; k <= right; k++)
                ans[top][k] = num++;
            top++;

            for (int p = top; p <= bottom; p++)
                ans[p][right] = num++;
            right--;

            if(top <= bottom) 
            {
                for (int p = right; p >= left; p--)
                    ans[bottom][p] = num++;
                bottom--;
            }

            if(left <= right) 
            {
                for (int p = bottom; p >= top; p--)
                    ans[p][left] = num++;
                left++;
            }
        }
        return ans;
    }
};