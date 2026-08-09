class Solution {
public:
    int minimumOperations(vector<int>& nums) {
       vector<bool> b(101);
       int n = 100; 
       for(int num : nums)
       {
            if(num != 0 && !b[num])
            {
                n--;
                b[num] = true;
            }
       }
    return 100 - n;
    }
};
