class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> t(n, INT_MAX);
        int l = 0;
        int sum = 0;
        int ans = INT_MAX;

        for(int r = 0; r < n; r++)
        {
            sum += arr[r];
            while(sum > target)
            {
                sum -= arr[l];
                l++;
            }
            if(sum == target)
            {
                if(l > 0 && t[l - 1] != INT_MAX)
                    ans = min(ans, r - l + 1 + t[l - 1]);
                  t[r] = r - l + 1;    
            }
            if(r > 0)
                t[r] = min(t[r], t[r - 1]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};