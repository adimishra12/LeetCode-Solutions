class Solution {
public:
    int subtractProductAndSum(int n) {
        int p = 1, s = 0;
        while(n > 0)
        {
            int a = n % 10;
            p *= a;
            s += a;
            n /= 10;
        }
        return p - s;
    }
};