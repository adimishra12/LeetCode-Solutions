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
    unordered_map<TreeNode*, int> robb;
    unordered_map<TreeNode*, int> notrob;
    int solve(TreeNode* node, bool par_rob)
    {
        if(!node)
            return 0;
        if(par_rob)
        {
            if(robb.count(node) > 0)
                return robb[node];
            return robb[node] = solve(node -> left, false) + solve(node -> right, false);    
        }  
        else
        {
            if(notrob.count(node) > 0)
                return notrob[node];
            return notrob[node] = max(node -> val + solve(node -> left, true) + solve(node -> right, true), solve(node -> left, false) + solve(node -> right, false)) ;    
        }  
    }
    int rob(TreeNode* root) {
        robb.clear();
        notrob.clear();
        return solve(root, false);
    }
};