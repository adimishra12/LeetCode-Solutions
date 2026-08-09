class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int Finalarea = 0;

        while (i < j) 
        {
            int minarea = min(height[i], height[j]);
            int width = j - i;
            int ar = minarea * width;

            Finalarea = max(Finalarea, ar);

            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return Finalarea;
    }
};