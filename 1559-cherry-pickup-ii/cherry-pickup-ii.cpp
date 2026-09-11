class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> t(m, vector<vector<int>>(n, vector<int>(n, 0)));

        for(int j1 = 0; j1 < n; j1++)
        {
            for(int j2 = 0; j2 < n; j2++)
            {
                if(j1 == j2)
                    t[m - 1][j1][j2] = grid[m - 1][j1]; 
                else
                    t[m - 1][j1][j2] = grid[m - 1][j1] + grid[m - 1][j2];    
            }
        }

        for(int i = m - 2; i >= 0; --i)
        {
            for(int j1 = 0; j1 < n; j1++)
            {
                for(int j2 = 0; j2 < n; j2++)
                {
                    int maxi =  -100000008;
                    for(int dj1 = -1; dj1 <= 1; dj1++)
                    {
                        for(int dj2 = -1; dj2 <= 1; dj2++)
                        {
                            int val = 0;
                            if(j1 == j2)
                                val =  grid[i][j1];
                            else
                                val = grid[i][j1] + grid[i][j2]; 
                            if(j1 + dj1 >= 0 && j1 + dj1 < n && j2 + dj2 >= 0 && j2 + dj2 < n)    
                                val += t[i + 1][j1 + dj1][j2 + dj2];

                            else
                                val += -100000008;   
                            maxi = max(maxi, val);    
                        }
                    }
                    t[i][j1][j2] = maxi; 
                }
            }
        }
        return t[0][0][n - 1];
    }
};