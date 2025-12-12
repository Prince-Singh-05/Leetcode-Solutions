class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = -1;
        int i = 0;
        int j = height.size() - 1;

        while (i < j) {
            int gap = j - i;
            int area = gap * min(height[i], height[j]);
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }

            max_area = max(max_area, area);
        }

        return max_area;

    }
};