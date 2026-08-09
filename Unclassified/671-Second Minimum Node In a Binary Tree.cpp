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
    long Smin = LONG_MAX;
    int minimum; 
    void helper(TreeNode* root)
    {
        if(!root)
            return;

        if(root -> val > minimum)
            Smin = min(Smin, (long)root -> val);
        helper(root -> left);
        helper(root -> right);        
    }
    int findSecondMinimumValue(TreeNode* root) {
        minimum = root -> val;
        helper(root);

        if(Smin != LONG_MAX)
            return Smin;
        else
            return -1;    
    }
};