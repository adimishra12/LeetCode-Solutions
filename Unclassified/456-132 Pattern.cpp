class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack < int > st;
        int n = nums.size(); 
        int c= INT_MIN;
        for (int i = n-1;i>=0;i--){
        if(nums[i]<c)
        return true;
        while(!st.empty()&&st.top()<nums[i])
        {
            c=st.top();
            st.pop();
        }
        st.push(nums[i]);
        
    }
    return false;
}
};