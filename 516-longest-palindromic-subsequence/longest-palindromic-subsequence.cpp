class Solution {
public:
    vector<vector<int>> t;
    int lcs(string s1, string s2, int l)
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
    int longestPalindromeSubseq(string s) {
        string rs = s;
        reverse(rs.begin(), rs.end());
        int n = s.length();
        t = vector<vector<int>>(n + 1,vector<int> (n + 1, 0));
        return lcs(s, rs, n); 
    }
};