class Solution {
public:
    int solve (vector <int> &n, int s, int e)
    {
        int pp = n[s];
        int ans = max(n[s+1] , n[s]);
        for (int i = s+2 ; i <= e ; ++i)
        {
            int money = n[i] + pp;
            pp = ans;
            ans = max(money,ans);
        }
        return ans;
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0],nums[1]);
        int a = solve(nums,0,nums.size()-2);
        int b = solve(nums,1,nums.size()-1);
        int ans1 = max(a,b);
        return ans1;
    }
    
};