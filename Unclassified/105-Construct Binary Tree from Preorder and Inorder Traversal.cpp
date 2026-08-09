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
    int idx = 0;
    unordered_map<int, int> mp;

    TreeNode* helper(vector<int>& preorder, int i, int j)
    {
        if(i > j)
            return nullptr;

        TreeNode* root = nullptr; 
        if(i <= j)
        {
            int rVal = preorder[idx];
            idx++;
            root = new TreeNode(rVal);
            int m = mp[rVal];

            root -> left = helper(preorder, i, m - 1);
            root -> right = helper(preorder, m + 1, j);
        }
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return helper(preorder, 0, inorder.size() - 1);
    }

};