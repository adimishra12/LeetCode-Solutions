class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini = INT_MAX;
        int count = 0;//odd
        for(int i : nums1)
        {
            count += i & 1;
            mini = min(mini, i);
        }
        return mini & 1 || count == 0;
    }
};