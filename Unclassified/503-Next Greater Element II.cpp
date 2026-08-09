class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans (nums.size(), -1);
        stack<int> st;

        for(int i = 0; i < 2 * nums.size(); i++)
        {
            int ind = i % nums.size();
            while(!st.empty() && nums[ind] > nums[st.top()])
            {
                ans[st.top()] = nums[ind];
                st.pop();
            }
            st.push(ind);
        }
        return ans;
    }
};