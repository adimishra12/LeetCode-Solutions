class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int f = 1;
        int curr_f = 1;
        int maxf = arr[0];

        for(int i = 1; i < arr.size(); i++)
        {
            if(arr[i] == arr[i - 1])
                curr_f++;
            else
                curr_f = 1;

            if(curr_f > f)
            {
                f = curr_f;
                maxf = arr[i];
            }        
        }
        return maxf;
    }
};