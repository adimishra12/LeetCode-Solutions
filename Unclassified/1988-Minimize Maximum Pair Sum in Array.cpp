class Solution {
public:
    int minPairSum(std::vector<int>& nums) 
    {
       sort(nums.begin(), nums.end());

        int left = 0, right = nums.size() - 1;

        int msum = INT_MIN;
        while(left < right) 
        {
            int csum = nums[left] + nums[right];
            msum = max(msum, csum);
            left++;
            right--;
        }
        return msum;
    }
};