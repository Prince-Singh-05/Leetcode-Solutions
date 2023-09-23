class Solution {
    public int findMin(int[] nums) {
        int s = 0;
        int e = nums.length-1;

        while(s <= e) {
            int mid = s+(e-s)/2;

            if(s == e) return nums[e];

            if(mid-1 >= 0 && nums[mid] < nums[mid-1]) {
                return nums[mid];
            } else if(mid+1 < nums.length && nums[mid] > nums[mid+1]) {
                return nums[mid+1];
            } else if(nums[e] > nums[mid]) {
                e = mid;
            } else {
                s = mid+1;
            }
        }

        return -1;

        // while(s < e) {
        //     int mid = s+(e-s)/2;

        //     if(nums[mid] < nums[e]) {
        //         e = mid;
        //     } else {
        //         s = mid+1;
        //     }
        // }

        // return nums[s];
    }
}