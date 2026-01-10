class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int sum = nums[i];
        int min_len = INT_MAX;

        while (i <= j && j <= nums.size()-1) {
            if (sum >= target) {
                min_len = min(min_len, j-i+1);
                sum -= nums[i++];
            } else {
                if (j < nums.size()-1)
                    sum += nums[++j];
                else break;
            }
        }

        return min_len == INT_MAX ? 0 : min_len;
    }
};