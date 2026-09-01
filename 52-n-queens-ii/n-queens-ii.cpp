class Solution {
public:
    bool valid(vector<vector<bool>>& board, int i, int j)
    {
        for(int k = 0; k <= i; k++)
        {
            if(board[k][j])
                return false;
            if(i - k >= 0 && j - k >= 0 && board[i - k][j - k])
                return false;
            if(i - k >= 0 && j + k < board.size() && board[i - k][j + k]) 
                return false;      
        }
        return true;
    }
    int solve(vector<vector<bool>>& board, int i)
    {
        if(i == board.size())
            return 1;
        int count = 0;
        for(int j = 0; j < board.size(); j++)
        {
            if(valid(board, i, j))
            {
                board[i][j] = true;
                count += solve(board, i + 1);
                board[i][j] = false;
            }
        } 
        return count;   
    }
    int totalNQueens(int n) {
        vector<vector<bool>> board(n, vector<bool>(n, false));
        return solve(board, 0);
    }

};