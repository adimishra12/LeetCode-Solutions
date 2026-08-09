class Solution {
public:
    void func(int i, unordered_map<char, string>& mp, string s, vector<string>& ans, string digits)
    {
        if(i == digits.size())
        {
            ans.push_back(s);
            return;
        }  
        for(int j = 0; j < mp[digits[i]].size(); j++)
        {
            s.push_back(mp[digits[i]][j]);
            func(i + 1, mp, s, ans, digits);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>mp = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};

        string str;
        vector<string> ans;
        func(0, mp, str, ans, digits);
        return ans;
    }
};