class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq(26, 0);
        vector<int> win(26, 0);
        vector<int> ans;
        if(s.length() < p.size())
            return ans;

        for(int i = 0; i < p.size(); i++)
        {
            freq[p[i] - 'a']++;
            win[s[i] - 'a']++;
        }    

        if(freq == win)
            ans.push_back(0);

        for(int i = p.size(); i < s.size(); i++)
        {
            win[s[i] - 'a']++;
            win[s[i - p.size()] - 'a']--;
            if(win == freq)
                ans.push_back(i - p.size() + 1);
        }    
        return ans;
    }
};