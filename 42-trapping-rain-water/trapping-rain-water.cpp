class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        if (n == 1) return 0;

        int maxi = 0;
        int area;
        vector<int> leftToRight(n);
        vector<int> rightToLeft(n);

        for (int i = 0; i<n; i++) {
            maxi = max(maxi, height[i]);
            leftToRight[i] = maxi;
        }

        maxi = 0;

        for (int i = n-1; i >= 0; i--) {
            maxi = max(maxi, height[i]);
            rightToLeft[i] = maxi;
        }

        for (int i = 0; i < n; i++) {
            area += min(leftToRight[i], rightToLeft[i]) - height[i];
        }

        return area;
    }
};