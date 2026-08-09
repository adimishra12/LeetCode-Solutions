
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int> ans;

        map<int, int> mp;

        for(int i : nums)
            mp[i]++;

        vector<pair<int, int>>p;

        for(auto i : mp)
            p.push_back(make_pair(i.second, i.first));

        sort(p.rbegin(), p.rend());

        int i = 0;
        while(i < p.size() && k != 0 )
        {
            ans.push_back(p[i].second);
            k--;
            i++;
        }       
        return ans; 
    }
};