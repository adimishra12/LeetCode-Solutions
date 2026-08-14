class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> mp;
        int i = 0, j = 0, n = s.size();
        int res = 0;    
        while (j < n) {
            mp[s[j]]++;
            while (mp[s[j]] > 2) {
                mp[s[i]]--;
                i++;
            }
            res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
};