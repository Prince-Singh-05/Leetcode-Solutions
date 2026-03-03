class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        if (target < matrix[0][0] || target > matrix[m-1][n-1]) return false;

        int row = 0;

        for (int i = 0; i < m; i++) {
            if (target <= matrix[i][n-1]) {
                row = i;
                break;
            }
        }

        int s = 0;
        int e = n-1;

        while (s <= e) {
            int mid = s + (e-s)/2;

            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] < target) {
                s = mid+1;
            } else {
                e = mid-1;
            }
        }

        return false;
    }
};