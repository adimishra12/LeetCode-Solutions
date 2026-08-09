class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int curr_sum = 0;
        int minlen = INT_MAX;
        for(int j = 0; j < nums.size(); j++)
        {
            curr_sum += nums[j];
            while(curr_sum >= target)
            {
                minlen = min(minlen, j - i + 1);
                curr_sum -= nums[i];
                i++;
            }
        }    
        if(minlen == INT_MAX)
            return 0;
        else
            return minlen;    

            
    }
};