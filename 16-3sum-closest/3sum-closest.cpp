class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 0;
        int temp = INT_MAX;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++)
        {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = n - 1;
            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                int diff = abs(target - sum);
                if(diff < temp)
                {
                    temp = diff;
                    ans = sum;
                }
                if(sum == target)
                    return sum;
                else if(sum < target)
                    j++;
                else
                    k--;    
            }  
        }
        return ans;
    }
};