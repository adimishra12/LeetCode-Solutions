class Solution {
public:
    int start = 1, count = 1, ans = -1;
    void dfs(vector<int>& edges, vector<int>& visited, int idx)
    {
        if(edges[idx] == -1)
            return;

        if(visited[idx] != 0)
        {
            if(visited[idx] >= start)
                ans = max(ans, count - visited[idx]);
            return;    
        }    
        visited[idx] = count;
        count++;
        dfs(edges, visited, edges[idx]);
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n, 0);
        for(int i = 0; i < n; i++)
        {
            if(visited[i] == 0)
            {
                dfs(edges, visited, i);
                start = count;
            }
        }
        return ans;
    }
};