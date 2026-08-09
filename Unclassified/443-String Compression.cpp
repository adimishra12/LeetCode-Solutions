class Solution {
public:
    int compress(vector<char>& chars) {
        
        int ans = 0;
        int i = 0;

        while(i < chars.size())
        {
            char curr_char = chars[i];
            int count = 0;

            while(i < chars.size() && chars[i] == curr_char)
            {
                count++;
                i++;
            }

            chars[ans] = curr_char;
            ans++;

            if(count > 1)
            {
                for(auto j : to_string(count))
                {
                    chars[ans] = j;
                    ans++;
                }    
            }
        }
        return ans;
    }
};