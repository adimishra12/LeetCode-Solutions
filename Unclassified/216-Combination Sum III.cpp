class Solution {
public:
    vector<vector<int>> ans;
    void backtracking(int k, int n, int start, vector<int>& path) {
        if(n<0 && k<0)
        return;
        if (n == 0 && k == 0) {
            ans.push_back(path);
            return;
        }
        for (int i =start; i <=9; ++i)
         {
            if (i >n || k <=0) 
            break;
            path.push_back(i);
            backtracking(k-1, n-i, i+1, path);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int> path;
        backtracking(k, n, 1, path);
        return ans;
    }
};