class Solution {
public:
    vector<vector<int>>t;
    int solve(vector<int>& nums, int i, int j)
    {
        if(i > j)
            return 0;
        if(t[i][j] != -1)
            return t[i][j];
        int cost = 0;
        int maxi = INT_MIN;    
        for(int k = i; k <= j; k++)
        {
            cost = nums[i - 1] * nums[k] * nums[j + 1] + solve(nums, k + 1, j) + solve(nums, i, k - 1);
            maxi = max(maxi, cost);
        }
        return t[i][j] = maxi;        
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        t.resize(n + 1, vector<int>(n + 1, -1));
        return solve(nums, 1, n);
    }
};