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
    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size();
        stack<TreeNode*> st;
        
        int i = 0;
        while(i < n)
        {
            int h = 0;
            while(i < n && traversal[i] == '-')
            {
                h++;
                i++;
            }
            int value = 0;
            while(i < n && isdigit(traversal[i]))
            {
                value = value * 10 + (traversal[i] - '0');
                i++;
            }
            while(st.size() > h)
                st.pop();
            TreeNode* root = new TreeNode(value);

            if(!st.empty())
            {
                if(!st.top() -> left)
                    st.top() -> left = root;
                else
                    st.top() -> right = root;    
            }
            st.push(root);
        }
        while(st.size() > 1)
            st.pop();
        return st.top();    
    }
};