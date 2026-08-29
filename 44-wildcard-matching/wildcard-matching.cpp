class Solution {
public:
    vector<vector<int>> t;
    bool solve(string &s, string &p, int i, int j)
    {
        if(i < 0 && j < 0)
            return true;

        if(i >= 0 && j < 0) 
            return false;

        if(i < 0 && j >= 0)
        {
            for(int k = 0; k <= j; k++)
                if(p[k] != '*')
                    return false;
            return true;
        }
        if(t[i][j] != -1)
            return t[i][j];

        if(s[i] == p[j] || p[j] == '?')
            return t[i][j] = solve(s, p, i - 1, j - 1);   

        if(p[j] == '*')
            return t[i][j] = solve(s, p, i - 1, j) || solve(s, p, i, j - 1);

        return t[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        t.resize(m, vector<int>(n, -1));
        return solve(s, p, m - 1, n - 1);
    }
};