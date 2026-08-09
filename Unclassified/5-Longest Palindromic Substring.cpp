class Solution {
public:
    int expand(string s, int l, int r)
    {
        while(l >= 0 && r < s.length() && s.at(l) == s.at(r))
            {l--; r++;}

        return r - l - 1;    
    }
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for(int i = 0; i < s.length(); i++)
        {
            int odd = expand(s, i, i);
            int even = expand(s, i, i + 1);
            int valid_len = max(odd, even);

            if((end - start) < valid_len)
            {
                start = i - (valid_len - 1) / 2;
                end = i + valid_len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};