class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int i = 0;int j;
        while(i<n)
        {
            int temp = s[0];
            for(j=0;j<n;j++)
            s[j]= s[j+1];
            s[n-1]= temp;
            if(s==goal) return true;
            i++;
        }
        return false;
        
    }
};