class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans = 0;
        long long g;
        long long st;
        for(int i = 0; i < nums.size(); i++)
            {
                for(int j = i + 1; j < nums.size(); j++)
                    {
                        g = gcd(nums[i] , nums[j]);
                        st = 1LL * nums[i] / g * (nums[j] / g);
                    ans = max(ans, st);
                    }
            }
        return ans;
    }
};