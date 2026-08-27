class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = nums[0];
        int f = nums[0];

        while(true) 
        {
            s = nums[s];
            f = nums[nums[f]];

            if(s == f)
                break;
        }

        int slow = nums[0];

        while(s != slow)
        {
            s = nums[s];
            slow = nums[slow];
        }
        return s;        
    }
};