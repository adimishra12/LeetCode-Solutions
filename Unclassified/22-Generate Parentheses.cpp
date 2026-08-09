class Solution {
public:
    vector<string> ans;

    void solve(string curr, int open_count, int close_count, int n) {
        
        if(curr.length() == 2 * n) 
        {
            ans.push_back(curr);
            return;
        }

        if(open_count < n)
            solve(curr + '(', open_count + 1, close_count, n);

        if(close_count < open_count)
            solve(curr + ')', open_count, close_count + 1, n);
    }

    vector<string> generateParenthesis(int n) {
        solve("", 0, 0, n);
        return ans;
    }
};