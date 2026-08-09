class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int valid = 0, j = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') 
            valid++;
            else 
            valid--;
            if (valid==0) {
                res+=s.substr(j+1,i-j-1);
                j=i+1;
            }
        }
        return res;
    }
};