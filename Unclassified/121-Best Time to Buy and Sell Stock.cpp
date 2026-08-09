class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int profit=0;
        for (int i = 1; i < prices.size(); i++) {
            int diff = prices[i]- min ;
            if (prices[i] < min) {
                min = prices[i];
            } 

            else if (diff > profit) {
                profit = diff;
            }
        }
        return profit;
    }
};