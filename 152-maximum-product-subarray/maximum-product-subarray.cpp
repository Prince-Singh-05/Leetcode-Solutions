class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest_prod = nums[0];
        int smallest_prod = 0;
        int ans = nums[0];

        for (int i = 1; i<nums.size(); i++) {
            int opt1 = largest_prod * nums[i];
            int opt2 = nums[i];
            int opt3 = smallest_prod * nums[i];
            largest_prod = max(opt1, max(opt2, opt3));
            smallest_prod = min(opt1, min(opt2, opt3));
            ans = max(ans, max(largest_prod, smallest_prod));
        }

        return ans;
    }
};