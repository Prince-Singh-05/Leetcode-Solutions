class Solution {

    public int findDuplicate(int[] nums) {
        
        // VISITED IDX

        /*
        int len = nums.length;
        for(int num : nums) {
            int idx = Math.abs(num);
            if(nums[idx] < 0) {
                return idx;
            }

            nums[idx] = -nums[idx];
        }

        return len;
        */

        // SLOW FAST POINTER

        int slow = 0;
        int fast = 0;

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        slow = 0;

        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
}