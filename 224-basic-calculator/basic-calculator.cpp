typedef long long ll;
class Solution {
public:

    int calculate(string s) {
        stack<ll> st;
        ll res = 0;
        ll num = 0;
        ll sym = 1;
        for (int i = 0; i < s.size(); i++)
        {
            if(isdigit(s[i]))
                num = num * 10 + (s[i] - '0');
            else if(s[i] == '+')
            {
                res += sym * num;
                num = 0;
                sym = 1;
            }
            else if(s[i] == '-')
            {
                res += sym * num;
                num = 0;
                sym = -1;
            }
            else if(s[i] == '(')
            {
                st.push(res);
                st.push(sym);
                res = 0;
                sym = 1;
            }
            else if(s[i] == ')')
            {
                res += sym * num;
                num = 0;
                ll prevSym = st.top();
                st.pop();

                ll prevres = st.top();
                st.pop();
                res = prevres + prevSym * res;
            }
        }
        res += sym * num;
        return (int)res;
    }
};