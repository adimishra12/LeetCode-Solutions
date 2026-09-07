class Solution {
public:
    bool canTransform(string start, string result) {
        int i = 0, j = 0;
        while(i < start.size() || j < result.size())
        {
            while(start[i] == 'X')
                i++;

            while(result[j] == 'X')
                j++;

            if(start[i] != result[j])    
                return false;

            if(start[i] == 'L' && i < j)
                return false;

            if(start[i] == 'R' && j < i)
                return false;

            i++; j++;                
        }
        return true;
    }
};