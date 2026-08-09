class Solution {
public:
    int gcd(int i, int j)
    {
        if(i == 0)
            return j;
        else
            return gcd(j % i, i);    
    }
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for(int i = 2; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
                if(gcd(i, j) == 1)
                    ans.push_back(to_string(j) + "/" + to_string(i));
        }
        return ans; 
    }
};
