class Solution {
public:
    vector<vector<__int128>> T;
    int solve(string s, string t, int m, int n)
    {
        for(int i = 0; i <= m; i++)
            T[i][0] = 1;

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(s[i - 1] == t[j - 1])
                {
                    if (T[i - 1][j] > INT_MAX - T[i - 1][j - 1])
                        T[i][j] = INT_MAX;
                    else
                        T[i][j] = T[i - 1][j] + T[i - 1][j - 1];
                }
                else
                    T[i][j] = T[i - 1][j];
            }
        }
        return T[m][n];
    }

    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        T.assign(m + 1, vector<__int128>(n + 1, 0));
        return solve(s, t, m, n);
    }
};