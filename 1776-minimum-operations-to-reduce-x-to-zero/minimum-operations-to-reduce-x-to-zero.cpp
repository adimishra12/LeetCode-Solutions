class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
            sum += nums[i];

        if(sum < x)
            return -1;

        int tar = sum - x;
        if(tar == 0)
            return nums.size();

        int l = 0;
        int currSum = 0;
        int maxi = -1;
        for(int r = 0; r < nums.size(); r++)
        {
            currSum += nums[r];
            while(currSum > tar && l <= r)
            {
                currSum -= nums[l];
                l++;
            }
            if(currSum == tar)
                maxi = max(maxi, r - l + 1);
        } 
        if(maxi == -1)
            return -1;
        return nums.size() - maxi;              
    }
};