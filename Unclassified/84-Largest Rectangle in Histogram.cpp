class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack <int> st; int nse, pse; int maxi = 0;
        for(int i = 0; i < heights.size(); i++)
        {
            while(!st.empty() && heights[st.top()] > heights[i])
            {
                int element = st.top();
                st.pop();
                nse = i;
                pse = st.empty() ? -1 : st.top();
                maxi = max(maxi, (nse - pse - 1) * heights[element]);
            }
            st.push(i);
        }
        while(!st.empty())
        {
            nse = heights.size();
            int element = st.top();
            st.pop();
            pse = st.empty() ? -1 : st.top();
            
            maxi = max(maxi, (nse - pse - 1) * heights[element]);
        }
        return maxi;
    }
};