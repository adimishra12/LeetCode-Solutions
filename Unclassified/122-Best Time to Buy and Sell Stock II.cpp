class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[0] < prices[i])
                max += prices[i] - prices[0];
            prices[0] = prices[i];
        }
        return max;
    }
};