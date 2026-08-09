class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int i = 0;
        int j = colors.size() - 1;
        int m = INT_MIN;

        while(i < j)
        {
            if(colors[i] != colors[j])
            {
                m = max(m, abs(i - j));
                break;
            }
            else
                j--;    
        }

        i = 0; j = colors.size() - 1;
        
        while(i < j)
        {
            if(colors[i] != colors[j])
            {
                m = max(m,  abs(i - j));
                break;
            }    
            else
                i++;    
        }

        return m;
    }
};