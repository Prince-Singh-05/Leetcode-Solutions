class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();
        if(target > matrix[m-1][n-1]) return false;

        int targetRow = 0;

        for(int row = 0; row < m; row++) {
            if(target <= matrix[row][n-1]) {
                targetRow = row;
                break;
            }
        }

        cout << targetRow << endl;

        int left = 0;
        int right = n-1;

        while(left <= right) {
            int mid = left + (right-left)/2;

            if(matrix[targetRow][mid] == target) {
                return true;
            }
            else if(matrix[targetRow][mid] < target) {
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }

        return false;
        
    }
};