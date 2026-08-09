class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] % 2 == 0)
            {
                nums[j] = 0;
                j++;
            }    
        }
        while(j < nums.size())
        {
            nums[j] = 1;
            j++;
        }
        return nums;
    }
};