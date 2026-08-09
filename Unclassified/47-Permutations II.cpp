class Solution {
public:
    set<vector<int>> s;
    void permutation(vector<int> &a, int left, int right)
    {

        if (left == right) 
        {
        s.insert(a);
        return;
        }

        for (int i = left; i <= right; i++) 
        {
        swap(a[left], a[i]);
        permutation(a, left + 1, right);
        swap(a[left], a[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        permutation (nums, 0, nums.size()-1);
        return vector<vector<int>>(s.begin(), s.end());
    }
};