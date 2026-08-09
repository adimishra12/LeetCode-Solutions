class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        int n = s.length();        
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mp;
            for (int j = i; j < n; j++) {
                mp[s[j]]++;
                int maxFreq = 0, minFreq = INT_MAX;
                for (auto i : mp) {
                    maxFreq = max(maxFreq, i.second);
                    minFreq = min(minFreq, i.second);
                }
                sum += (maxFreq - minFreq);
            }
        }
        return sum;
    }
};
