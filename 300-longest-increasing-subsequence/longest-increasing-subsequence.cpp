class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n, 1);
        int maxi = 1;

        for(int i = 0; i < n; i++)
        {
            for(int prev = 0; prev < i; prev++)
                if(nums[prev] < nums[i])
                    t[i] = max(t[i], 1 + t[prev]);
            maxi = max(maxi, t[i]);
        }    
        return maxi;            
    }
};