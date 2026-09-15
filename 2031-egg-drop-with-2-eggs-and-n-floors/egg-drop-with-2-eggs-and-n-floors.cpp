class Solution {
public:
    int solve(int e, int f, vector<vector<int>>& t)
    {
        if(f == 0 || f == 1)
            return f;

        if(e == 1)
            return f;

        if(t[e][f] != -1)
            return t[e][f];

        int mini = INT_MAX;

        for(int k = 1; k <= f; k++)
        {   int low = 0; int high = 0;

            if(t[e - 1][k - 1] != -1)
                low = t[e - 1][k - 1];
            else
            {
                low = solve(e - 1, k - 1, t);
                t[e - 1][k - 1] = low;    
            }

            if(t[e][f - k] != -1)
                high = t[e][f - k];
            else
            {
                high = solve(e, f - k, t);
                t[e][f - k] = high;
            }    
            int temp = 1 + max(low, high);
            mini = min(mini, temp);
        }  
        return t[e][f] = mini;      
    }
    int twoEggDrop(int n) {
        vector<vector<int>> t(3, vector<int>(n + 1, -1));
        return solve(2, n, t);
    }
};