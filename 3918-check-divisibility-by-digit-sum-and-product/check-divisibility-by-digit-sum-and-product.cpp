class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;int sumd = 0, prod = 1;
        while(temp > 0)
        {
            int a = temp % 10;
            sumd += a;
            prod *= a;
            temp /= 10;
        }
        if(n % (sumd + prod) == 0)
            return true;
        return false;    
    }
};