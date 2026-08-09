class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> stringStack;
        string curr = "";
        int num = 0;

        for(char ch : s)
        {
            if(isdigit(ch))
                num = num * 10 + (ch - '0');

            else if(ch == '[')
            {
                numStack.push(num);
                stringStack.push(curr);
                num = 0;
                curr = "";
            }
            else if(ch == ']')
            {
                int multiply = numStack.top();
                numStack.pop();

                string p = stringStack.top();
                stringStack.pop();

                string temp = "";
                while(multiply--)
                    temp += curr;

                curr = p + temp;    
            }
            else
                curr += ch;    
        }
        return curr; 
    }
};