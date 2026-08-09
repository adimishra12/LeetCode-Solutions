class Solution {
public:
    void solve(int idx, int n, int k, vector<int>& c, vector<vector<int>>& ans)
    {
        if(c.size() == k)
        {
            ans.push_back(c);
            return;
        }
        for(int i = idx; i <= n; i++)
        {
            c.push_back(i);
            solve(i + 1, n, k, c, ans);
            c.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> c;
        solve(1, n, k, c, ans);
        return ans;
    }
};