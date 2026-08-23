class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        long long n = lower;
        for(int num : nums)
            {
                if(num < lower || num > upper)
                    continue;
                if(n < num)
                    ans.push_back({(int)n, num -1});
                n = (long long)num + 1;
                if(n > upper)
                    break;
            }
        if(n <= upper)
            ans.push_back({(int)n, upper});
        return ans;
    }
};