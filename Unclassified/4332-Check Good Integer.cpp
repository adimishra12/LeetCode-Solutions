class Solution {
public:
    bool checkGoodInteger(int n) {
        int ds = 0, ss = 0;
        while(n > 0)
        {
            int a = n % 10;
            ds += a;
            ss += (a*a);
            n /= 10;
        }
        if((ss - ds) >= 50)
            return true;
        return false;    
    }
};