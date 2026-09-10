class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int count = 0;
        int i = 0;
        long long missno = 1;

        while(missno <= n)
        {
            if(i < nums.size() && nums[i] <= missno)
            {
                missno += nums[i];
                i++;
            }  
            else
            {
                count++;
                missno += missno;
            }    
        }
        return count;
    }
};