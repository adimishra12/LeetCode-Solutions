class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<int> ans;
        int ele = nums[0];
        int i = 0;
        while(i < nums.size())
        {
            if(ele < nums[i])
            {
                ans.push_back(ele);
                i--;
            }
            i++;
            ele++;
        }
    return ans;
    }
};