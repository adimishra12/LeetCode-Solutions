class Solution {
public:
    vector<vector<int>> t;
    int solve(int i, int j, vector<int>& prefixSum)
    {
        if(i >= j)
            return 0;

        if(t[i][j] != -1)
            return t[i][j];

        int score = 0;    

        for(int line = i; line <= j - 1; line++)
        {
            int leftSum = prefixSum[line] - (i - 1 >= 0 ? prefixSum[i - 1] : 0);
            int rightSum = prefixSum[j] - prefixSum[line];
            
            if(leftSum < rightSum)
                score = max(score, leftSum + solve(i, line, prefixSum));

            else if(rightSum < leftSum)
                score = max(score, rightSum + solve(line + 1, j, prefixSum));

            else
                score = max({score, leftSum + solve(i, line, prefixSum), rightSum + solve(line + 1, j, prefixSum)});         
        }   
        return t[i][j] = score;     
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> prefixSum(n, 0);

        prefixSum[0] = stoneValue[0];

        t.resize(501, vector<int>(501, -1));

        for(int i = 1; i < n; i++)
            prefixSum[i] = prefixSum[i - 1] + stoneValue[i];

        return solve(0, n - 1, prefixSum);        
    }
};