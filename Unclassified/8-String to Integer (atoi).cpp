class Solution {
    int solve(int i, int n, string &s, int sign, long res){
        if(i>=n || !isdigit(s[i]))
            return int(sign*res);
        res=res*10+(s[i]-'0');
        if(sign*res>=INT_MAX)
            return INT_MAX;
        if(sign*res<=INT_MIN)
            return INT_MIN;
        
        return solve(i+1, n, s, sign, res);
    }

public:
    int myAtoi(string s) {
        int n=s.size(), i=0, sign=1;
        long res=0;
        
        while(i<n && (s[i]==' '))
            i++;
        if(s[i]=='-' || s[i]=='+'){
            if(s[i]=='-')
                sign=-1;
            i++;
        }
        return solve(i, n, s, sign, res);
    }
};