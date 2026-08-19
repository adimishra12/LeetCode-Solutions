class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = 0, currentMax = 0, maxSum = nums[0], currentMin = 0, minSum = nums[0];

        for(int x : nums)
        {

            sum += x;

            currentMax = max(x, currentMax + x);
            maxSum = max(maxSum, currentMax);

            currentMin = min(x, currentMin + x);
            minSum = min(minSum, currentMin);
        }
        if(maxSum < 0)
            return maxSum;

        return max(maxSum, sum - minSum);
    }
};