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
    vector<int> helper(TreeNode* root)
    {
        if(!root)
            return {0, INT_MAX, INT_MIN, 0};

        vector<int> l = helper(root -> left);
        vector<int> r = helper(root -> right);

        if(l[0] || l[2] >= root -> val || r[0] || r[1] <= root -> val)
            return {1, INT_MAX, INT_MIN, 0};  

        ans = max(ans, l[3] + r[3] + root -> val);

        return {0, min(l[1], root -> val), max(r[2], root -> val), l[3] + r[3] + root -> val};      
    }
    int maxSumBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};