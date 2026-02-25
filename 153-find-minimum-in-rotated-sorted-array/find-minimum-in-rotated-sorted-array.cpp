class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        int ans = INT_MAX;

        while (start <= end) {
            int mid = start + (end-start)/2;

            if (nums[mid] <= nums[end]) {
                end = mid-1;
                ans = min(ans, nums[mid]);
            } else if (nums[start] < nums[end]) {
                end = mid-1;
            } else {
                start = mid+1;
            }
        }

        return ans;
    }
};