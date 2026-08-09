class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        vector<int> fr(26, 0);
        for(int i = 0; i < word.size(); i++)
            fr[word[i] - 'a']++;
        sort(fr.rbegin(), fr.rend());
        int i = 0;
        while(i < 26 && fr[i] > 0)
        {
            ans += fr[i] * (i / 8 + 1);
            i++;
        } 
        return ans;   
    }
};