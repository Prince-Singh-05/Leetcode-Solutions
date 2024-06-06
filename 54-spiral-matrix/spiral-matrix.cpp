class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

         vector<int> ans;
        int r = matrix.size();
        int c = matrix[0].size();
        
        int startingRow = 0;
        int endingRow = r-1;
        int startingCol = 0;
        int endingCol = c-1;
        
        int totalElement = r*c;
        int count = 0;
        
        while(count < totalElement) {
            
            // top row
            
            for(int i = startingCol; i <= endingCol && count < totalElement; i++) {
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            
            startingRow++;
            
            
            // right col
            
            for(int i = startingRow; i <= endingRow && count < totalElement; i++) {
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            
            endingCol--;
            
            
            // bottom row
            
            for(int i = endingCol; i >= startingCol && count < totalElement; i--) {
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            
            endingRow--;
            
            
            // left col
            
            for(int i = endingRow; i >= startingRow && count < totalElement; i--) {
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            
            startingCol++;
        }
        
        return ans;
        
       
    }
};