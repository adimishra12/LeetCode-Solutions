class Solution {
public:
    vector<vector<int>> ans;

    void solve(int idx, vector<int>& nums, vector<int>& path) {

        if (idx == nums.size()) 
        {
            ans.push_back(path);
            return;
        }
        solve(idx + 1, nums, path);//picking
        //skipping
        path.push_back(nums[idx]);

        solve(idx + 1, nums, path);
            
        path.pop_back();
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        solve(0, nums, path);
        return ans;
    }
};