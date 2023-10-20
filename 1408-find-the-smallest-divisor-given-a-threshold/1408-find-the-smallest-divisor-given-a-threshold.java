class Solution {

    public boolean lessThanThreshold(int nums[], int div, int threshold) {
        int sum = 0;
        
        for(int i : nums) {
            sum += Math.ceil((double) (i) / (double) (div));
        }

        return (sum <= threshold);
    }

    public int smallestDivisor(int[] nums, int threshold) {
        int maxi = Integer.MIN_VALUE;
        int n = nums.length;

        if(n > threshold) return -1;

        for(int i : nums) {
            maxi = Math.max(maxi, i);
        }

        int s = 1, e = maxi;

        while(s <= e) {
            int mid = (s+e)/2;

            if(lessThanThreshold(nums, mid, threshold)) {
                e = mid-1;
            } else {
                s = mid+1;
            }
        }

        return s;
    }
}