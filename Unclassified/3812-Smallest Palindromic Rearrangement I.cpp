class Solution {
public:
    string smallestPalindrome(string s) {
        sort(s.begin() + 0, s.begin() + s.length() / 2);
        for(int i = 0; i < s.length() / 2; i++)
        {
            s[s.length() - 1 - i] = s[i];
        }
        return s;
    }
};