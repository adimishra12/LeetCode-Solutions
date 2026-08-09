class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        char ch = '+';
        int i = 0;

        while(i < s.size())
        {
            if(s[i] == ' ')
                i++;
            
            else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] =='/')
                ch = s[i++];
            
            else 
            {
                int num = 0;
                while(i < s.size() && isdigit(s[i]))
                    num = num * 10 + (s[i++] - '0');

                if(ch == '+')
                    st.push(num);

                else if( ch == '-')
                    st.push(num * -1);

                else
                {
                    int x = st.top();
                    st.pop();

                    if(ch == '*') 
                        st.push(num * x);

                    else 
                        st.push(x / num);
                }
            }
        }
        int ans = 0;
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
    return ans;   
    }
};