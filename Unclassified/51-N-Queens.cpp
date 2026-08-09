class Solution {
public:
    void solve(int col, vector<string>& board, vector<int>& leftRow, vector<int>& lowerdiagonal, vector<int>& upperdiagonal, vector<vector<string>>& ans, int n)
    {
        //base casw
        if(col == n)
            {ans.push_back(board);
            return;}

        for(int row = 0; row < n; row++)
        {
            if(leftRow[row] == 0 && upperdiagonal[n - 1 + col - row] == 0 && lowerdiagonal[row + col] == 0)
            {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                upperdiagonal[n - 1 + col - row] = 1;
                lowerdiagonal[row + col] = 1;

                solve(col + 1, board, leftRow, lowerdiagonal, upperdiagonal, ans, n);

                board[row][col] = '.';
                leftRow[row] = 0;
                upperdiagonal[n - 1 + col - row] = 0;
                lowerdiagonal[row + col] = 0;
            }
        }    
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        vector<int> leftRow(n, 0), upperdiagonal(2 * n - 1, 0), lowerdiagonal(2 * n - 1, 0);
        string s(n, '.');
        for(int i = 0; i < n; i++)
            board[i] = s;
        solve(0, board, leftRow, lowerdiagonal, upperdiagonal, ans, n);
        return ans;
    }
};