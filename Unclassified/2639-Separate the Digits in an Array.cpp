class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        vector<int> ans_tmp;

        for(int i = 0; i < nums.size(); i++)
        {
            int temp = nums[i];
            while(temp)
            {
                ans_tmp.push_back(temp % 10);
                temp /= 10;
            }

            reverse(ans_tmp.begin(), ans_tmp.end());

            for(int j = 0; j < ans_tmp.size(); j++)
            {
                ans.push_back(ans_tmp[j]);
            }
            ans_tmp.clear();
        }    
        return ans;    
    }
};