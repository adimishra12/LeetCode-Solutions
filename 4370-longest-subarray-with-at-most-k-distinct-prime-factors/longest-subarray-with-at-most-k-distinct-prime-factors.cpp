class Solution {
public:
    vector<int> primefact(int n)
    {
        vector<int> res;

        for(int i = 2; i * i <= n; i++)
            {
                if(n % i == 0)
                {   
                    res.push_back(i);
                    while(n % i == 0)
                        n /= i;
                } 
            }
        if(n > 1)
            res.push_back(n);
        return res;
    }
    int longestSubarray(vector<int>& nums, int k) {
        vector<vector<int>> fact(nums.size());
        
        for(int i = 0; i < nums.size(); i++)
            fact[i] = primefact(nums[i]);
        
        unordered_map<int, int> mp;

        int l = 0, dist = 0, ans = 0;
        for(int r = 0; r < nums.size(); r++)
            {
                for(int i: fact[r])
                    {
                        if(mp[i] == 0)
                            dist++;
                        mp[i]++;
                    }
                while(dist > k)
                    {
                        for(int i : fact[l])
                            {
                               mp[i]--;
                               if(mp[i] == 0)
                                   dist--;
                            }
                        l++;
                    }
                ans = max(ans, r - l + 1);
            }
        return ans;
    }
};