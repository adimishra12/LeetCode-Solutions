/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root, int targetSum, int sum, vector<vector<int>>& res, vector<int>& arr)
    {
        if(!root)
            return;

        arr.push_back(root -> val);
        sum += root -> val;

        if(root -> left == nullptr && root -> right == nullptr && sum == targetSum)
            res.push_back(arr); 

        helper(root -> left, targetSum, sum, res, arr);    
        helper(root -> right, targetSum, sum, res, arr);

        arr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> res;
        vector<int> arr;
        helper(root, targetSum, 0, res, arr);
        return res;
    }
};