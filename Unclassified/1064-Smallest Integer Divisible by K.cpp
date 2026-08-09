class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k == 2 || k == 5)
            return -1;
        long long  a;
        for(int i = 1; i <= k; i++)
        {
            a = (a * 10 + 1) % k;
            if (a == 0)
            {
                return i;
            }
        }
        return -1;
    }
};