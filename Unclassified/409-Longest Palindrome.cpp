class Solution {
public:
    int longestPalindrome(string s) {
        int odd_fr = 0;
        unordered_map<char, int> f;
        for(char ch : s)
        {
            f[ch]++;
            if(f[ch] % 2 == 0)
                odd_fr--;
            else
                odd_fr++;    
        }
        if(odd_fr > 1)
            return s.length() - odd_fr + 1;
        else
            return s.length();    
    }
};