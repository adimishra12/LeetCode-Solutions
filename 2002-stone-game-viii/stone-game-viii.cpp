class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefixSum = stones;

        for(int i = 1; i < n; i++)
            prefixSum[i] += prefixSum[i - 1];

        int allstones = prefixSum[n - 1];

        for(int i = n - 2; i >= 1; i--)
           allstones = max(allstones, prefixSum[i] - allstones);

        return allstones;   
    }
};