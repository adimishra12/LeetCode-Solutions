class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans(k);
        int s = mat[0].size();
        for(int i = 0; i < mat.size(); i++)
            mat[i].push_back(i);

        sort(mat.begin(), mat.end());

        for(int i = 0; i < k; i++)
            ans[i] = mat[i][s];
        return ans;    
    }
};