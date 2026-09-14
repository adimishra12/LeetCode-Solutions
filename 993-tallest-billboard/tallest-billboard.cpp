class Solution {
public:
    int solve(vector<int>& rods, int i, int j, vector<vector<int>>& t)
    {
        if(i >= rods.size())
        {
            if(j == 0)
                return 0;
            return INT_MIN;    
        }
        if(t[i][j + 5000] != -1)
            return t[i][j + 5000];

        int skip = solve(rods, i + 1, j, t);
        int add1 = rods[i] + solve(rods, i + 1, j - rods[i], t);
        int add2 = rods[i] + solve(rods, i + 1, j + rods[i], t);

        return t[i][j + 5000] = max({skip, add1, add2});    
    }
    int tallestBillboard(vector<int>& rods) {
        vector<vector<int>>t (21, vector<int>(10101, -1));
        return solve(rods, 0, 0, t) / 2;
    }
};