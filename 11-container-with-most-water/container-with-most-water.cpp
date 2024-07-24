class Solution {
public:
    int maxArea(vector<int>& height) {

        int n = height.size();
        int left = 0;
        int right = n-1;
        int maxAmount = 0;

        while(left < right) {
            int len = right-left;
            int bre = min(height[left], height[right]);
            int currAmount = len * bre;

            maxAmount = max(maxAmount, currAmount);

            if(height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return maxAmount;
        
    }
};