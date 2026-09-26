class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for(auto i : knowledge)
            mp[i[0]] = i[1];

        string ans;
        int j = -1;
        for(int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if(ch == '(')
                j = i;

            else if(ch == ')') 
            {
                string subs = s.substr(j + 1, i - j - 1);
                if(mp.count(subs))
                    ans += mp[subs];

                else
                    ans += "?";

                j = -1;        
            }

            else if(j < 0)
                ans+= ch;   
        } 
        return ans;   
    }
};