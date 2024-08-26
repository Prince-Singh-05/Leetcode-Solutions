class Solution {
public:
    int maxScore(vector<int>& points, int k) {
        int leftSum = 0, rightSum = 0;
        int n = points.size();
        
        for(int i = 0; i<k; i++) {
            leftSum += points[i];
        }

        int maxScore = leftSum;
        int r = n-1;

        for(int i = k-1; i>=0; i--) {
            leftSum = leftSum - points[i];
            rightSum = rightSum + points[r];

            maxScore = max(maxScore, leftSum + rightSum);
            r = r-1;
        }

        return maxScore;
    }
};