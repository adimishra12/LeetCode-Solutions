class Solution {
public:
    long long perfectPairs(vector<int>& nums) {

        for(int i = 0; i < nums.size(); i++)
            nums[i] = abs(nums[i]);

        sort(nums.begin(), nums.end());
        
        int l = 0;
        long ans = 0;
        for(int r = 0; r < nums.size(); r++)
        {
            while(nums[r] > 2L * nums[l])
                l++;
            ans += r - l;    
        }    
        return ans;
    }
};
