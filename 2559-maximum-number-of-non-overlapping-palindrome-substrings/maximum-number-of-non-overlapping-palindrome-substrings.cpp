class Solution {
public:
    bool palindrome(string& s, int i, int j)
        {
            string r = s;
            reverse(r.begin() + i, r.begin() + j + 1);
            return r == s;
        }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        int count = 0;
       
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                int boundary = j - i + 1;
                if(palindrome(s, i, j) && boundary >= k)
                {
                    count++;
                    i = j;
                    break;
                } 
                if(boundary > k)
                    break;
            }
        }
        return count;
    }
};