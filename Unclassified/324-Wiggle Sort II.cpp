class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mid = (nums.size() - 1) / 2;
        int i = 0;
        int j = mid + 1 ;
        vector<int> res;
        reverse(nums.begin(), nums.begin() + mid + 1);
        reverse(nums.begin() + mid + 1, nums.end());
        while(i <= mid && j < nums.size())
        {
            res.push_back(nums[i]);
            res.push_back(nums[j]);
            i++;j++;
        }
        while(i <= mid)
        {
            res.push_back(nums[i]);
            i++;
        }
        nums = res;
    }
};