class Solution {
public:
    bool solve(vector<int>& nums, int k, int idx)
    {
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] <= idx)
            {
                cnt++;
                i++;
            }
        }
       return cnt >= k ? true : false;
    }
    int minCapability(vector<int>& nums, int k) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        int ans = r;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if(solve(nums, k, mid))
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};