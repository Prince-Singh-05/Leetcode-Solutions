class Solution {
    public boolean isMonotonic(int[] nums) {
        
        int n = nums.length;

        if(nums[0] <= nums[n-1]) {
            for(int i = 0; i<n-1; i++) {

                int j = i+1;
                if(nums[i] > nums[j]) {
                    return false;
                }
            }
        } else if(nums[0] >= nums[n-1]) {
            for(int i = 0; i<n-1; i++) {
                
                int j = i+1;
                if(nums[i] < nums[j]) {
                    return false;
                }
            }
        }
        
        return true;
    }
}