class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        if (nums.size() == 1) {
            if (nums[0] < k) return 1;
            else return 0;
        }

        int low = 0;
        int high = 0;
        int prod = 1;
        int res = 0;

        while (low < nums.size()) {
            prod *= nums[high];

            if (prod >= k) {
                low++;
                high = low;
                prod = 1;
            } else {
                res++;
                high++;
                if (high >= nums.size()) {
                    low++;
                    high = low;
                    prod = 1;
                }
            }
        }
        return res;
    }
};