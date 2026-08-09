class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxS = 0, WinS = 0; int n = nums.size();

        for(int i = 0; i < k; i++)
            maxS += nums[i];

        WinS = maxS;

        for(int i = k; i < nums.size(); i++)
        {
            WinS += nums[i] - nums[i - k];
            maxS = max(maxS, WinS);
        }
        
        return maxS / k;
    }
};