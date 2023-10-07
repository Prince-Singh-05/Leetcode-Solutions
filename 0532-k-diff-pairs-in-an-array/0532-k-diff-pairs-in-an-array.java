class Solution {
    public int findPairs(int[] nums, int k) {
        int count = 0;
        Arrays.sort(nums);

        for(int i = 0; i<nums.length-1; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1;

            while(j < nums.length) {
                if(Math.abs(nums[i] - nums[j]) == k) {
                    count++;
                }
                j++;
                while(j < nums.length && nums[j] == nums[j-1]) j++;
            }
        }

        return count;
    }
}