class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<int> t(k + 1, 0);
        int ways = 0;

        while(t[k] < n)
        {
            ways++;
            for(int i = k; i >= 1; i--)
                t[i] = t[i] + t[i - 1] + 1;
        }
        return ways;
    }
};