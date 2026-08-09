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
    int ans = 0;

    int helper(TreeNode* root, int parent)
    {
        if(!root)
            return 0;

        int left = helper(root -> left, root -> val);
        int right = helper(root -> right, root -> val);

        ans = max(ans, left + right);

        if(root -> val == parent)
            return max(left, right) + 1;
        else
            return 0;        
    }
    int longestUnivaluePath(TreeNode* root) {
        helper(root, -1);
        return ans;
    }
};