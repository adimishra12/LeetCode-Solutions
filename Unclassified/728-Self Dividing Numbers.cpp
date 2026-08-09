class Solution {
public:
    bool divisibility(int x) 
    {
        int temp = x;
        while (temp != 0) 
        {
            int a = temp % 10;
            if (a == 0 || x % a != 0) 
                return false;  
            temp /= 10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector <int> res;
        for(int i = left; i <= right; i++)
        {
            if (divisibility(i) == true)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};