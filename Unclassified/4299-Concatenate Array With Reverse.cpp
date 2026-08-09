class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int i  = 0;
        vector<int> ans;
        while(i < nums.size()){
            ans.push_back(nums[i]);
            i++;}
        for(int i = nums.size() - 1; i >= 0; --i)
            ans.push_back(nums[i]); 
        return ans;      
    }
};