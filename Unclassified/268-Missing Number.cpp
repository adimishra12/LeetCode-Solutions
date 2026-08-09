class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res= 0;
        int n= nums.size();

        for (int i = 1;i <= n;i++) 
        {
            res^=i;
        }
        for (int i = 0;i < nums.size();i++) {
            res^=nums[i];
        }
        return res;
    }
};