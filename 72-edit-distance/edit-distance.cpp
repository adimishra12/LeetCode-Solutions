class Solution {
public:
    int n, m;
    vector<vector<int>> t;
    int solve(string word1, string word2, int i, int j)
    {
        if(i < 0)
            return j + 1;
        if(j < 0)
            return i + 1;
        if(t[i][j] != -1)
            return t[i][j];

        if(word1[i] == word2[j])
            return solve(word1, word2, i - 1, j -1);

        return t[i][j] = 1 + min({solve(word1, word2, i - 1, j), solve(word1, word2, i, j - 1), solve(word1, word2, i - 1, j - 1)});        

    }
    int minDistance(string word1, string word2) {
        n = word1.size();
        m = word2.size();
        t.resize(n + 1, vector<int>(m, -1));
        return solve(word1, word2, n - 1, m - 1);
    }
};