class Solution {
    public int searchInsert(int[] nums, int target) {
        int s = 0;
        int e = nums.length-1;
        int ans = 0;

        while(s <= e) {
            int mid = s+(e-s)/2;

            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target) {
                ans = mid+1;
                s = mid+1;
            } else {
                ans = mid;
                e = mid-1;
            }  
        }

        return ans;
    }
}