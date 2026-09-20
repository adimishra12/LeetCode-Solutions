class Solution {
public:
    int reverseDegree(string s) {
        int prod = 0;
        for(int i = 0; i < s.size(); i++)
            prod += ('z' - s[i] + 1) * (i + 1);

        return prod;    
    }
};