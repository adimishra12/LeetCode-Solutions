class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int num : nums)
            mp[num]++;

        int limit = nums.size() / 3;
        vector<int> ans;
        for(auto i : mp)
        {
            int ele = i.first;
            if(i.second > limit)
                ans.push_back(ele);
        }
        return ans;
    }
};