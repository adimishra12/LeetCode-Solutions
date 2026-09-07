class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum1 = 0;
        int sum2 = 0;
        int maxSum = 0;
        for(int i = 0; i < k; i++)
            sum1 += cardPoints[i];

        maxSum = sum1;
        int r = cardPoints.size() - 1;
        for(int i = k - 1; i >= 0; --i)
        {
            sum1 -= cardPoints[i];
            sum2 += cardPoints[r];
            r--;

            maxSum = max(maxSum, sum2 + sum1);
        }
    return maxSum;
    }
};