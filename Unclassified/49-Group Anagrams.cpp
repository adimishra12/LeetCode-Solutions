class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> s;
        for(string i : strs)
        {
            string curr_word = i;
            sort(curr_word.begin(), curr_word.end());
            mp[curr_word].push_back(i);
        }

        for(auto &i : mp)
            s.push_back(i.second);
        
        return s;
    }
};