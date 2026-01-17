class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        
        int low = 0;
        int high = 0;
        long long prod = 1;
        int res = 0;

        while (high < nums.size()) {
            prod *= nums[high];

            while (low <= high && prod >= k) {
                prod = prod / nums[low];
                low++;
            }

            res += high-low+1;
            high++;
        }
        return res;
    }
};