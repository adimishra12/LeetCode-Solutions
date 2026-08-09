class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());
        long double total = 0;

        int k = min(prices.size(), discounts.size());
        for(int i = 0; i < k; i++) {
            total += (long double)prices[i] * (100 - discounts[i])/100.0L;
        }

        for(int i = k; i < prices.size(); i++)
        {
            total += prices[i];
        }

        return (double)total;
    }
};