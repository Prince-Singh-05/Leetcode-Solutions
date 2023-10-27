class Solution {
public:

    int countPartitions(vector<int> nums, int maxSum) {
        int partitions = 1;
        long currSubarraySum = 0;

        for(int v : nums) {
            if(currSubarraySum + v <= maxSum) {
                currSubarraySum += v;
            } else {
                partitions++;
                currSubarraySum = v;
            }
        }

        return partitions;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = nums[0];
        int high = 0;

        for(int v : nums) {
            low = max(low, v);
            high += v;
        }

        while(low <= high) {
            int mid = (low + high)/2;
            int partitions = countPartitions(nums, mid);

            if(partitions > k) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }

        return low;
    }
};