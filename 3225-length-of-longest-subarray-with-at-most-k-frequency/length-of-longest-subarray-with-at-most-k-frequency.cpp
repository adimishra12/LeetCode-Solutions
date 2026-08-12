class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int maxL = 0;
        int i = 0, j = 0;
        
        while(j < nums.size())
        {
            int &count = mp[nums[j]];
            count++;

            while(count > k)
                mp[nums[i++]]--;

            maxL = max(maxL, j - i + 1);  
            j++;  
        }
        return maxL;
    }
};