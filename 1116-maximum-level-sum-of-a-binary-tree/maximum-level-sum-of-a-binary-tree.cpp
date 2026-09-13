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
    void dfs(TreeNode* root, int i, map<int, int>& mp)
    {
        if(!root)
            return;

        mp[i] += root -> val;
        dfs(root -> left, i + 1, mp);
        dfs(root -> right, i + 1, mp);    
    }
    int maxLevelSum(TreeNode* root) {
       map<int, int> mp;
       dfs(root, 1, mp);

       int maxsum = INT_MIN;
       int ans = 0;
       for(auto i : mp)
        {
            int f= i.first;
            int s = i.second;
            if(s > maxsum)
            {
                maxsum = s;
                ans = f;

            }
        }
        return ans;
    }
};