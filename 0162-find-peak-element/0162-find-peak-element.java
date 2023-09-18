class Solution {
    public int findPeakElement(int[] nums) {
        int s = 0;
        int e = nums.length - 1;
        int ans = 0;

        while(s<e) {
            int mid = s + (e-s)/2;

            if(nums[mid] < nums[mid+1]) {
                ans = mid+1;
                s = mid+1;
            } else {
                ans = mid;
                e = mid;
            }
        }

        return ans;
    }
}