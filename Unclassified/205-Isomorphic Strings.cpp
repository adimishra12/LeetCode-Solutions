class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> Si(150,0);
        vector<int> Ti(150,0);
        if (s.size()!=t.size()) return false;
        for(int i = 0 ; i<s.size();i++)
        {
            if (Si[s[i]]!=Ti[t[i]]) return false;
            Si[s[i]]=i+1;
            Ti[t[i]]=i+1;
        }
        return true;
        
    }
};