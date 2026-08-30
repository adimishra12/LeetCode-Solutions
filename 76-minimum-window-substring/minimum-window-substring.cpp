class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        int minlen = INT_MAX;

        unordered_map<char, int> mp;
        mp.reserve(256);

        int count = 0;

        for(char ch : t)
            mp[ch]++;

        int l = 0, r = 0;
        int start = -1;
        while(r < m)
        {
            if(mp[s[r]] > 0)
                count++;
            mp[s[r]]--;
            while(count == n)
            {
                if(r - l + 1 < minlen)
                {
                    minlen = r - l + 1;
                    start = l;
                }
                
                mp[s[l]]++;
                if(mp[s[l]] > 0)
                    count--;  

                l++;      
            }
            r++;    
        }
        return start == -1 ? "" : s.substr(start, minlen);
    }
};