class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
         int n = nums.size();
        vector<int> t(n, 1), count(n, 1);
        int maxi = 1;

        for(int i = 0; i < n; i++)
        {
            for(int prev = 0; prev < i; prev++)
            {
                if(nums[prev] < nums[i] && 1 + t[prev] > t[i])
                {
                    t[i] = 1 + t[prev];
                    count[i] = count[prev];
                }
                else if(nums[prev] < nums[i] && 1 + t[prev] == t[i]) 
                    count[i] += count[prev];   
            }       
            maxi = max(maxi, t[i]);
        }    
        int cnt = 0;
        for(int i = 0; i < n; i++)
            if(t[i] == maxi)
                cnt += count[i];
        return cnt;     
    }
};