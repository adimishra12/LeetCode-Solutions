class Solution {
public:
    int sumDecoded(vector<long long>& nums) {
        const long long mod = 1000000007LL;
        long long ans = 0;
        for(long long num : nums)
            {
                int width = num % 10;
                long long  d = num / 10;
                string s = to_string(d);
                long long  x= stoll(s.substr(0, width));
                long long   y = stoll(s.substr(width));
                long long value = 1;
                x %= mod;
                
                while(y > 0)
                    {
                        if(y & 1)
                            value = (value * x) % mod;
                        x = (x * x) % mod;
                        y >>= 1;
                    }
                ans = (ans+value) % mod;
            }
        return (int)ans;
    }
};