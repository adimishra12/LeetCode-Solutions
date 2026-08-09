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
    bool Symmetric(TreeNode* n1, TreeNode* n2) {

        if (n1 == NULL && n2 == NULL) 
        return true;

        if (n1 == NULL || n2 == NULL) 
        return false;

        bool lefthalf = Symmetric(n1->left, n2->right);
        bool righthalf = Symmetric(n1->right, n2->left);

        return (n1->val == n2->val && lefthalf && righthalf);
    }
    bool isSymmetric(TreeNode* root) {
        return Symmetric(root, root);
    }
};