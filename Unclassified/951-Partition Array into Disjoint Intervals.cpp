class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int maxtn = nums[0];
        int lefttn = nums[0];
        int ans = 1;
        for ( int i = 1; i < nums.size(); i++)
        {
            maxtn = max (maxtn , nums[i]);
            if (nums[i] < lefttn)
            {
                ans = i + 1;
                lefttn = maxtn;
            }
        }
        return ans;
    }
};