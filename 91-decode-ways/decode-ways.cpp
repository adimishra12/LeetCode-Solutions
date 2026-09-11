class Solution {
public:
    int solve(string s, vector<int>& t, int idx, int n)
    {
        if(idx == n)
            return 1;
        if(t[idx] != -1)
            return t[idx];

        int ans = 0;
        if(s[idx] != '0')
            ans += solve(s, t, idx + 1, n);

        if(idx + 1 < n && (s[idx] == '1' || s[idx] == '2' && s[idx + 1] <= '6'))
            ans += solve(s, t, idx + 2, n);

        return t[idx] = ans;               
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> t(n + 1, -1);
        return solve(s, t, 0, n);
    }
};