class Solution {
public:
    string simplifyPath(string path) {
       stack<string> st;
       string ans;
       for(int i = 0; i < path.size(); i++)
       {
            if(path[i] == '/')
                continue;

            string str;
            while(i < path.size() && path[i] != '/')
            {
                str += path[i];
                i++;
            }
            if(str == ".")
                continue;

            else if(str == "..")
            {
                if(!st.empty())
                    st.pop();
            }  

            else
                st.push(str);
       }
       while(!st.empty())
       {
            ans = "/" + st.top() + ans;
            st.pop();
       }
       if(ans.size() == 0)
            return "/";

        return ans;     
    }
};