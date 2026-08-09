class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maximum = nums[0];
        for(int i = 0; i < nums.size() ; i++){
            if(i > maximum) 
            return false;
            maximum = max(maximum, i+nums[i]);
        }
        return true;
    }
};