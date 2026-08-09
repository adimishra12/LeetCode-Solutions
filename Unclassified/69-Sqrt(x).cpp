class Solution {
public:
    int mySqrt(int x) {
        long long beg = 0, end = x, ans = 0;
    
        while (beg <= end)
        {
        long long mid = beg + (end - beg) / 2;
        
        if (mid * mid <= x)
        {
            ans = mid;         
            beg = mid + 1;    
        }
        else
        end = mid - 1;   
        }
    return ans;
    }
};