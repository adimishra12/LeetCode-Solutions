class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0, count = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        
        for(int i : s)
        {
            if(s.find(i - 1) == s.end())
            {
                count = 1;
                int num = i;
                while(s.find(num + 1) != s.end())
                {
                    count++;
                    num++;
                }
                longest = max(longest, count);
            }    
        }  
        return longest;
    }
};