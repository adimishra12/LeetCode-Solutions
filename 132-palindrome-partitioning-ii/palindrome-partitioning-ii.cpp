class Solution {
public: 
    int n;
    vector<vector<int>> t;
    bool isPalindrome(string& s, int i, int j)
    {
        if(i >= j)
            return true;
        while(i < j)
        {
            if(s[i] != s[j])
                return false;
            i++;
            j--;    
        }
        return true;
    }
    int solve(string& s, int i, int j)
    {
        if(i >= j)
            return 0;

        if(isPalindrome(s, i, j))
        {
            t[i][j] = 0;
            return 0;
        }

        if(t[i][j] != -1)   
            return t[i][j];

        int mini = INT_MAX;    
        for(int k = i; k <= j - 1; k++)  
        {
            if(isPalindrome(s, i, k))
            {
                int temp = 1 + solve(s, k + 1, j);
                if(temp < mini)
                    mini = temp;
            }        
        }       
        return t[i][j] = mini;
    }
    int minCut(string s) {
        n = s.size();
        t = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
        return solve(s, 0, n - 1);
    }
};