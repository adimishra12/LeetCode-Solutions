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
    int helper(TreeNode* root, int a)
    {
        if(root == nullptr)
            return 0;
        a = a * 10 + root -> val;
        if(root -> left == nullptr && root -> right == nullptr)   
            return a;
        return helper(root -> left, a) + helper(root -> right, a);     
    }
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
};