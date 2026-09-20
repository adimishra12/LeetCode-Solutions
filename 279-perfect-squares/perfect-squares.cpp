class Solution {
public:
    int numSquares(int n) {
        vector<int> t(n + 1, 1000000009);
        t[0] = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j * j <= i; j++)
                t[i] = min(t[i], t[i - j * j] + 1);
        return t[n];
    }
};