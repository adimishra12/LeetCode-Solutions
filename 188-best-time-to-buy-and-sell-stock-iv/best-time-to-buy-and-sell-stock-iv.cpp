class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> t1(k + 1, -10000);
        vector<int> t2(k + 1);

        for(int i = 0; i < prices.size(); i++)
        {
            for(int j = 1; j <= k; j++)
            {
                t1[j] = max(t1[j], t2[j - 1] - prices[i]);
                t2[j] = max(t2[j], t1[j] + prices[i]);
            }
        }
        return t2[k];
    }
};