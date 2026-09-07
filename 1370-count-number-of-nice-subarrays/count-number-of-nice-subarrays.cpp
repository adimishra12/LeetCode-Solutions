class Solution {
public:
    int atMost(vector<int>& nums, int k)
    {
        if(k < 0)
            return 0;
            
        int j = 0;
        int ans = 0;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            while(sum > k)
            {
                sum -= nums[j];
                j++;
            }
            ans += i - j + 1;    
        } 
        return ans;   
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int& i : nums)
            i %= 2;
        return atMost(nums, k) - atMost(nums, k - 1);    
    }
};