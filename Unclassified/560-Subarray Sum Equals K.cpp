class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0;
        int ans = 0;

        mp[sum] = 1;
        for(int i : nums)
        {
            sum += i;
            int num = sum - k;
            
            if(mp.find(num) != mp.end())
                ans += mp[num];

            mp[sum] ++ ;    
        }
        return ans;
    }
};