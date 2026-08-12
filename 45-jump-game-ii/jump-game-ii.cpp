class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int end = 0;
        int maxi = 0;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            maxi = max(maxi, i + nums[i]);
            if(maxi >= nums.size() - 1)
            {
                ans++;
                break;
            }
            if(i == end)
            {
                ans++;
                end = maxi;
            }
        }
        return ans;
    }
};