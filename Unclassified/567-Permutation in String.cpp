class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> f(26, 0);
        int count = s1.length();

        for(char ch : s1)
            f[ch - 'a']++;

        for(int i = 0, j = 0; j < s2.length(); j++)
        {
            if(f[s2[j] - 'a'] > 0)
                count--;
            f[s2[j] - 'a']--;    

            if(j - i + 1 > s1.size())
            {
                if(f[s2[i] - 'a'] >= 0)
                    count++;
                f[s2[i] - 'a']++;
                i++; 
            }
            
            if(count == 0)
                return true;
        }
        return false;
    }
};