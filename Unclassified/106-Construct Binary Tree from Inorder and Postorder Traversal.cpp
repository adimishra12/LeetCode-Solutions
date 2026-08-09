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
    unordered_map<int , int> mp;

    TreeNode* helper(int s, int e, int &i, vector<int> &inorder, vector<int> &postorder)
    {
        if(s > e)
            return nullptr;

        TreeNode* root = new TreeNode(postorder[i]);
        int j = mp[root -> val];
        i--;
        root -> right = helper(j + 1, e, i, inorder, postorder);
        root -> left = helper(s, j - 1, i, inorder, postorder);

        return root;    
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int i = postorder.size() - 1;

        for(int j = 0; j < inorder.size(); j++)
            mp[inorder[j]] = j;
        return helper(0, inorder.size() - 1, i, inorder, postorder);     
    }
};