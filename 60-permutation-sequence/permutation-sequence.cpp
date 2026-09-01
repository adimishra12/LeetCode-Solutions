class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> arr;
        int fact = 1;
        for(int i = 1; i <= n; i++)
        {
            fact *= i;
            arr.push_back(i);
        }

        fact /= n;
        k = k - 1;
        string ans;
        
        while(1)
        {
            int r = k / fact;

            ans += to_string(arr[r]);
            arr.erase(arr.begin() + r);

            if(arr.empty())
                break;

            k %= fact;
            fact /= arr.size();    
        }
        return ans;
    }
};