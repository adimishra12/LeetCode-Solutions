class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();

        vector<int> t(n, 1);
        for(int j = 0; j < n; j++)
        {
            for(int i = 0; i < j; i++)
            {
                bool flag = true;
                for(int k = 0; k < m; k++)
                {
                    if(strs[k][i] > strs[k][j])
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag)
                    t[j] = max(t[j], t[i] + 1);
            }
        }
        return n - *max_element(t.begin(), t.end());
    }
};