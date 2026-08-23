class Solution {
public:
    bool isPalindromic(string s) {
        string str ="";
        for(char ch : s){
            int ascii = (unsigned char)ch;
            for(int i = 7; i >= 0; i--)
                str += ((ascii >> i) & 1) + '0';
        }
    int l = 0, r = str.size() - 1;
        while(l < r)
        {
            if(str[l] != str[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};