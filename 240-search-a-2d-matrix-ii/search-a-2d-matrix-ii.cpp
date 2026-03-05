class Solution {
private:
    bool binarySearch(vector<vector<int>>& matrix, int target, int row, int n) {
        int start = 0;
        int end = n-1;

        while (start <= end) {
            int mid = start + (end-start)/2;

            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] < target) {
                start = mid+1;
            } else {
                end = mid-1;
            }
        }

        return false;
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i<m; i++) {
            bool found = binarySearch(matrix, target, i, n);

            if (found) return true;
        }

        return false;
    }
};