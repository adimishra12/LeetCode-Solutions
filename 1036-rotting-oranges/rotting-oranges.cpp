class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        int visited[m][n];
        int countfresh = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;;
                }
                else
                    visited[i][j] = 0;

                if(grid[i][j] == 1)
                    countfresh++;    
            }
        }
        int time = 0;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        int count = 0;
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();
             
            for(int i = 0; i < 4; i++)
            {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
                {
                    q.push({{nrow, ncol}, t + 1});
                    visited[nrow][ncol] = 2;
                    count++;
                }
            }
        }
        if(count != countfresh)
            return -1;
        return time;    
    }
};