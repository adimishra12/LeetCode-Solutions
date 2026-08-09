class Solution {
public:
    void permutation(vector<int> &a, int start, vector<vector<int>> &result)
    {

        if (start == a.size()) 
        {
        result.push_back(a);
        return;
        }

        for (int i = start; i < a.size(); i++) 
        {
        swap(a[start], a[i]);
        permutation(a, start + 1, result);
        swap(a[start], a[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;

        permutation(nums, 0, result);

        return result;
    }
};