class Solution {
private:
    int countElem(vector<vector<int>>& matrix, int guess, int n, int m) {
        int row = n-1;
        int col = 0;

        int count = 0;

        while (row >= 0 && col < m) {
            int elem = matrix[row][col];

            if (elem <= guess) {
                count += row+1;
                col++;
            } else {
                row--;
            }
        }

        return count;
    }

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = matrix[0][0];
        int high = matrix[n-1][m-1];

        int ans = 0;

        while (low <= high) {
            int mid = low + (high-low)/2;

            int count = countElem(matrix, mid, n, m);

            if (count >= k) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return ans;
    }
};