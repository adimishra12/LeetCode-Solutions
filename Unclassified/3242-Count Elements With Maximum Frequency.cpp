class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int maxf = 0, currf = 1, result = 0;

        for (int i = 1; i < nums.size(); i++) 
        {
            if (nums[i] == nums[i-1]) 
            currf++;

            else 
            {
                if (currf > maxf) 
                {
                    maxf = currf;
                    result = currf;
                } 
                else if (currf == maxf) 
                {
                    result += currf;
                }
                currf = 1;
            }
        }
        if (currf > maxf)
        result = currf;
        else if (currf == maxf)
        result += currf;

        return result;
    }
};