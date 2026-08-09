class Solution {
public:
    bool isValid(string word) {
        int hyphen = 0;

        for (int i = 0; i < word.size(); i++) 
        {
            char c = word[i];

            if (isdigit(c))
                return false;

            if (c == '-') 
            {
                hyphen++;
                if (hyphen > 1)
                    return false;

                if (i == 0 || i == word.size() - 1)
                    return false;

                if (!islower(word[i - 1]) || !islower(word[i + 1]))
                    return false;
            }

            else if (c == '!' || c == '.' || c == ',') 
            {
                if (i != word.size() - 1)
                    return false;
            }

            else if (!islower(c))
                return false;
        }
        return true;
    }

    int countValidWords(string sentence) {
        stringstream ss(sentence);
        string word;
        int count = 0;

        while (ss >> word) 
        {
            if (isValid(word))
                count++;
        }

        return count;
    }
};