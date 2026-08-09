
class Solution {
public:
    int robbing(vector<int>&nums,int index,vector<int> &temp)
    {
        if(index>=nums.size())
        {
            return 0;
        }

        if(temp[index]!=-1) 
        return temp[index];

        int in = nums[index]+robbing(nums,index+2,temp);
    
        int x =0+robbing(nums,index+1,temp);
        return temp[index]=max(in,x);


    }
    int rob(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int index = 0;
        vector<int> temp(nums.size(), -1);
        return robbing(nums,index,temp);
    }
};