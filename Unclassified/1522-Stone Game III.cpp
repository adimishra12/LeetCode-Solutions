class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int dp1 = 0, dp2 = 0, dp3 = 0;
        int best = INT_MIN;
        for(int i = stoneValue.size() - 1; i >= 0; i--)
        {
            int take1 = stoneValue[i] - dp1;
            int take2 = INT_MIN;
            if(i + 1 < stoneValue.size())
            {
                
                take2 = stoneValue[i] + stoneValue[i + 1] - dp2;
            }
            int take3 = INT_MIN;
            if(i + 2 < stoneValue.size())
            {
                
                take3 = stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp3;
            }
        best = max({take1, take2, take3});
        dp3 = dp2;
        dp2 = dp1;
        dp1 = best;
        }
        

        if(dp1 > 0)
            return "Alice";
        else if(dp1 < 0)   
            return "Bob";
        else
            return "Tie";     
        
    }
};