class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int r1 = min_element(nums.begin(), nums.end()) - nums.begin();
        int r2 = max_element(nums.begin(), nums.end()) - nums.begin();

        int left = min(r1, r2);
        int right = max(r1, r2);
        return min({right + 1, n - left, (left + 1) + (n - right)});
    }
};