class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        const int N = 1e9;
        vector<int> t(sum + 1, N);
        t[0] = 0;
        for(int i : nums)
            {
                vector<pair<int, int>> cand;
                int val = i;
                int cost = 0;
                while(val <= sum)
                    {
                        cand.push_back({val, cost});
                        val *= 2;
                        cost++;
                    }
                val = i / 2;
                cost = 1;
                while(val > 0)
                    {
                        cand.push_back({val, cost});
                        val /= 2;
                        cost++;
                    }
                vector<int> t1 = t;
                for(auto& c : cand)
                    {
                        int v = c.first;
                        int ca = c.second;
                        for(int j = sum ; j >= v; j--)
                            if(t[j - v] != N)
                                t1[j] = min(t1[j], t[j - v] + ca);
                    }
                t = move(t1);
            }
        if(t[sum] == N)
            return -1;
        else
            return t[sum];
    }
};