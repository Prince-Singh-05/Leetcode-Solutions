class Solution {
    public boolean containsDuplicate(int[] nums) {

        // Arrays.sort(nums);

        // for(int i = 1; i<nums.length; i++) {
        //     if(nums[i] == nums[i-1]) return true;
        // }

        // return false;

        HashMap<Integer, Integer> seen = new HashMap<>();
        for(int i : nums) {
            if(seen.containsKey(i) && seen.get(i) >= 1) {
                return true;
            }

            seen.put(i, seen.getOrDefault(i, 0) + 1);
        }

        return false;

    }
}