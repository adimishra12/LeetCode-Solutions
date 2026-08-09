class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        for(int i = 0; i < word.length(); i++)
        {
            char ch = word[i];
            if(ch >= 'A' && ch <= 'Z')
                count++;
        }

        if(count == 0 || count == word.length() || (count == 1 && (word[0] >= 'A' && word[0] <= 'Z')))
            return true;
        else 
            return false;    

        
            
    }
};
