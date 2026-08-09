class Solution {
public:
    bool palin (string &s, int i, int j)
    {
        while(i<j)
        {
            if (s[i++]!=s[j--])
            {
                return false;
            }
            
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length()-1;

        while ( i < j )
        {
            if (s[i]!=s[j])
            {
                return palin (s,i+1,j) || palin (s,i,j-1);
            }
            i++;j--;
        }
        return true;
    }
};