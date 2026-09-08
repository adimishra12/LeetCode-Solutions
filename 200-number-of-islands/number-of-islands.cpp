class Solution {
public:
    int n, m;
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& visited)
    {
        visited[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};

            for(int i = 0; i < 4; i++)
            {
                int newrow = row + delrow[i];
                int newcol = col + delcol[i];
                if(newrow >= 0 && newrow < m && newcol >=0 && newcol < n && !visited[newrow][newcol] && grid[newrow][newcol] == '1')
                {
                    visited[newrow][newcol] = 1;
                    q.push({newrow, newcol});
                }
            }
        }
       
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int cnt = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(!visited[i][j] && grid[i][j] == '1')
                {    
                    cnt++;
                    bfs(i, j, grid, visited);
                }    
            }
        }
        return cnt;
    }
};