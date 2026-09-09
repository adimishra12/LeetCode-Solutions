class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> t(n + 2, vector<int> (2, 0));

        for(int i = n - 1; i >= 0; --i)
        {
            t[i][1] = max(-prices[i] + t[i + 1][0], t[i + 1][1]);
            t[i][0] = max(prices[i] + t[i + 2][1], t[i + 1][0]);
        }
        return t[0][1];
    }
};