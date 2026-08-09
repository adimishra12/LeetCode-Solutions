class Solution {
private:
    void dfs(int node, vector<vector<int>>& adjlist, vector<int>& vis)
    {
        vis[node] = 1;
        for(auto it : adjlist[node])
        {
            if(!vis[it])
                dfs(it, adjlist, vis);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjlist(n);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(isConnected[i][j] == 1 && i != j)
                {
                    adjlist[j].push_back(i);
                    adjlist[i].push_back(j);
                }
            }
        }
        vector<int> vis(n, 0);
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                count++;
                dfs(i, adjlist, vis);
            }
        }
    return count;
    }
};