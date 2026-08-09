class Solution {
public:

    vector<vector<int>> ans;

    void Subset(int start,vector<int> &nums,vector<int> &ds)
    {
        ans.push_back(ds);
        for (int i = start;i<nums.size();i++)
        {
            if(i!=start && nums[i]==nums[i-1])
            continue;
            ds.push_back(nums[i]);
            Subset(i+1,nums,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ds;
        sort(nums.begin(),nums.end());
        Subset(0,nums,ds);
        return ans;
        
    }
};