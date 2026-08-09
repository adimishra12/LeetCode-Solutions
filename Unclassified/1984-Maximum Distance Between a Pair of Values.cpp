class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int d = 0;
        int i = 0;
        int j = 0;
        while(i < n && j < m)
        {
            if(i <= j && nums1[i] <= nums2[j])
            {
                d = max(d, abs(i - j));
                j++;
            }
            else if(i <= j)
                i++;
            else 
                j++;    
        }
        return d;
    }
};