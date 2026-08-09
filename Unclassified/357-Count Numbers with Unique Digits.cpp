class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0)
            return 1;

        int ans = 10;
        int prev_counted = 9;
        int nleft = 9;

        for(int i = 2; i <= n && nleft > 0; i++)
        {
            prev_counted *= nleft;
            ans += prev_counted;
            nleft--;
        }  
        return ans;  
    }
};