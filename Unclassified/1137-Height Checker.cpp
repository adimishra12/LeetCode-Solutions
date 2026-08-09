class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> h = heights;
        sort(h.begin(), h.end());
        int i = 0, j = 0, count = 0;

        while(i < heights.size() && j < h.size())
        {
            if(heights[i] == h[j])
            {
                i++;
                j++;
            }
            else
            {
                count++;
                i++;
                j++;
            }
        }
        return count;
    }
};