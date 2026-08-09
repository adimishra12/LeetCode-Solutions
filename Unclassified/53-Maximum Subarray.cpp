class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maximum = INT_MIN;

        for(int i:nums){
            if(sum < 0 ) 
            sum = 0;
            sum +=i;
            maximum = max(maximum, sum);
        }
        return maximum;
    }
};