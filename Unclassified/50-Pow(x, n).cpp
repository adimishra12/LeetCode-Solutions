class Solution {
private:
    double solve(double x,long long n) {
        if (n==0) 
        return 1;
        double half=solve(x,n/2);
        if (n%2==0)
        {
            return half*half;
        } 
        else
        {
            return x*half*half;
        }
    }

public:
    double myPow(double x,int n) {
        long long num=n;
        if (num<0) 
        {
            x=1/x;
            num=-num;
        }
        return solve(x,num);
    }
};