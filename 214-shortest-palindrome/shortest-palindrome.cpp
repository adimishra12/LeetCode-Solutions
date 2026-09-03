class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        int i = 0;
        for(int j = 0; j < n; j++)
            if(s[i] == s[n - j - 1])
                i++;

        if(i == n)
            return s;
        string r = s.substr(i, n);
        reverse(r.begin(), r.end());
        return r + shortestPalindrome(s.substr(0, i)) + s.substr(i);            
    }
};