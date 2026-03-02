class Solution {
private:
    bool possible(vector<int>& nums, int k, int guess) {
        int subarray_sum = 0;
        int subarray = 1;

        for (int n: nums) {
            if (subarray_sum + n <= guess) {
                subarray_sum += n;
            } else {
                subarray++;
                subarray_sum = n;

                if (subarray > k) return false;
            }
        }

        return true;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < k) return -1;

        int low = INT_MIN;
        int high = 0;

        for (int n: nums) {
            low = max(low, n);
            high += n;
        }

        int res = high;

        while (low <= high) {
            int mid = low + (high-low)/2;

            if (possible(nums, k, mid)) {
                res = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return res;
    }
};