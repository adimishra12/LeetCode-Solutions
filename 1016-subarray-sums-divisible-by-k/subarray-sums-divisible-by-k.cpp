class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int psum = 0;
        int cnt = 0;
        for(int num : nums)
        {
            psum += num;

            int remainder = psum % k;

            if(remainder < 0)
                remainder += k;

            if(mp.find(remainder) != mp.end())
            {
                cnt += mp[remainder];
                mp[remainder] += 1;
            }
            else
                mp[remainder] = 1;    
        }
        return cnt;
    }
};