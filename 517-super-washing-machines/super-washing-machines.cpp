class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = 0;
        int n = machines.size();
        for(int i = 0; i < n; i++)
            sum += machines[i];

        if(sum % n > 0)
            return -1;

        int t = sum / n;
        int ans = 0;
        int r = 0;
        for(int i : machines)
        {
            r = i + r - t;
            ans = max({ans, abs(r), i - t});
        }  
        return ans;      
    }
};