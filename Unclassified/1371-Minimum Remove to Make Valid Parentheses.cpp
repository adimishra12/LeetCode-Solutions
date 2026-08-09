class Solution {
public:
    string minRemoveToMakeValid(string s) {
        set<int> set;
        stack<int> st;
        string ans = "";
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
                st.push(i);

            if(s[i] == ')')    
            {
                if(st.empty())
                    set.insert(i);
                else
                    st.pop();    
            }
        }

        while(!st.empty())
        {
            set.insert(st.top());
            st.pop();
        }

        for(int i = 0; i < s.size(); i++)
        {
            if(set.find(i) == set.end())
                ans += s[i];
        }
        return ans;
    }
};