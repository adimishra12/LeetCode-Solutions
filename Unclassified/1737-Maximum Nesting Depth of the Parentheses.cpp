class Solution {
public:
    int maxDepth(string s) {
        int p = 0;
        int mp = 0; 
        for(char ch : s) {
            if(ch == '(') {
                p++;                     
                mp=max(mp,p); 
            } 
            else if(ch == ')') {
                p--; 
            }
        }
        return mp;
    }
};