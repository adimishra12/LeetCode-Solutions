class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        int left = 0;
        int right = r * c -1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            int row = mid / c;
            int col = mid % c;
            if(matrix[row][col] > target)
                right = mid - 1;
            else if(matrix[row][col] < target) 
                left = mid + 1;
            else
                return true;       
        }
        return false;
    }
};