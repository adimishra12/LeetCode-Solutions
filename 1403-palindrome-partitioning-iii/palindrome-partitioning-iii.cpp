class Solution {
public:
    int n;
    int t[201][201];
    int calCost(string& s, int start, int end)
    {
        int cost = 0;
        while(start < end)
        {
            if(s[start] != s[end])
                cost++;
            start++;
            end--;
        }        
        return cost;
    }
    int solve(string& s, int k, int idx)
    {
        if(k == 0)  
            return calCost(s, idx, n - 1);

        if(t[idx][k] != -1)
            return t[idx][k];        

        int mini = 101;
        for(int i = idx; i < n - k; i++)
        {
            int c = calCost(s, idx, i) + solve(s, k - 1, i + 1);
            mini = min(mini, c);
        }   
        return t[idx][k] = mini;     
    }
    int palindromePartition(string s, int k) {
        n = s.size();
        memset(t, -1, sizeof(t));
        return solve(s, k - 1, 0);
    }
};