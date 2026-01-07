class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int min_diff = INT_MAX;
        int result_sum = 0;

        for (int i = 0; i < n-2; i++) {

            if (i > 0 && nums[i] == nums[i-1]) continue;

            int left = i+1;
            int right = n-1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int diff = abs(sum - target);

                if (diff < min_diff) {
                    min_diff = diff;
                    result_sum = sum;
                }

                if (sum == target) {
                    return sum;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }        
        }

        return result_sum;
    }
};