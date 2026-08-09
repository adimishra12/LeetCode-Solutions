class Solution {
public:
    int largestAltitude(vector<int>& gain) 
    {
        int maxi = INT_MIN;
        for(int i  = 0; i <= gain.size(); i++)
        {
            int a = 0;
            for(int j = 0; j < i; j++)
                a += gain[j];
            maxi = max(maxi, a);    
        }
        return maxi;
    }
};