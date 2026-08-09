class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<int> d(n, -1);
        int h = 1;
        long long s = 0;
         d[0] = 1;
        for(int i = 1; i < n; i++)
            {
                d[i] = depth(parent, d, i);
                h = max(h, d[i]);
            }
        for(int i = 0; i < n; i++)
            s += 1LL * nums[i] * (h - d[i]+1);
        
        return s;  
    }
    int depth(const vector<int>& parent, vector<int>& d, int i)
    {
        if(d[i] != -1)
            return d[i];
        return d[i] = depth(parent, d, parent[i]) + 1;
    }
};