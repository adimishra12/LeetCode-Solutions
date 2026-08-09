class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int>ans;

        int i=0;
        int j=0;

        while( i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] != nums2[j])
            {
                if(nums1[i] > nums2[j]) 
                    j++;
                else 
                    i++;
            }
            else
            {
                if(i >= 1 && nums1[i] ==  nums1[i-1]) 
                    i++;
                else
                {
                    ans.push_back(nums1[i]);
                    i++;
                    j++;
                }
            }
        }
        return ans;
    }
};