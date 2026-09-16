class Solution {
public:
    int mod = 1e9 + 7;
    int distinctSubseqII(string s) {
        vector<int> t(26, 0); 
        int total = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int curr = total + 1;
            int ch = s[i] - 'a';
            curr = (curr - t[ch] + mod) % mod;
            t[ch] = (t[ch] + curr) % mod;
            total = (total + curr) % mod;
        }
        return total;
    }
};