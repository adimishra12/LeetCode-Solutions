class Solution {
public:
    int count(vector<vector<int>>& matrix, int mid)
    {
        int cnt = 0;
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                if(matrix[i][j] <= mid) 
                    cnt++;
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0];
        int r = matrix[n - 1][n - 1];

        while(l < r)
        {
            int mid = (l + r) >> 1;
            int cnt = count(matrix, mid);

            if(cnt >= k)
                r = mid;
            else
                l = mid +  1;    
        }
        return l;
    }
};