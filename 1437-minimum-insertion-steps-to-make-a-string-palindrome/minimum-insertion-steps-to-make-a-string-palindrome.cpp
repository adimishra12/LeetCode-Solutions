class Solution {
public:
    int n;
    vector<vector<int>> t;
    int lps(string s1, string s2, int l)
    {
        for(int i = 1; i < l + 1; i++)
        {
            for(int j = 1; j < l + 1; j++)
            {
                if(s1[i - 1] == s2[j - 1])
                    t[i][j] = 1 + t[i - 1][j - 1];
                else
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);    
            }
        }
        return t[l][l];
    }
    int minInsertions(string s) {
        n = s.length();
        string rs = s;
        reverse(rs.begin(), rs.end());
        t.resize(n + 1, vector<int>(n + 1, 0));
        return s.length() - lps(s, rs, n);
    }
};