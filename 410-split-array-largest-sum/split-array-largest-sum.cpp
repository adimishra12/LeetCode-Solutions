class Solution {
public:
    vector<vector<int>> t;
    int n;
    int solve(vector<int>& nums, int k, int idx)
    {
        if(idx < n && k == 0)
            return -1;
        if(idx == n && k > 0)
            return -1;
        if(idx == n && k == 0)
            return 0;
        if(t[idx][k] != -1)
            return t[idx][k];

        int sum = 0;
        int minians = INT_MAX;
        for(int i = idx; i < n; i++)
        {
            sum += nums[i];
            int temp = solve(nums, k - 1, i + 1);
            if(temp >= 0)
            {
                temp = max(temp, sum);
                minians = min(minians, temp);
            }
        } 
        return t[idx][k] = minians;               
    }
    int splitArray(vector<int>& nums, int k) {
        n = nums.size();
        t.resize(n + 1, vector<int> (k + 1, -1));
        return solve(nums, k, 0);
    }
};