class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        int m = 0;
        if(n == 2)
            return stones[1] - stones[0];
        for(int i = 2; i < n; i++)
            m = max(m, stones[i] - stones[i - 2]);
        return m;
    }
};