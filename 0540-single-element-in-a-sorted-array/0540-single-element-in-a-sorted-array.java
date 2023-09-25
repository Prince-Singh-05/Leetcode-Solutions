class Solution {
    public int singleNonDuplicate(int[] nums) {
        
        // BINARY SEARCH O(log n)
        /*
        int n = nums.length;
        int s = 0;
        int e = n-1;

        while(s <= e) {
            int mid = s+(e-s)/2;

            if(s == e) return nums[s];

            if(mid%2 == 1) {
                if(mid+1 < n && nums[mid] == nums[mid-1]) {
                    s = mid+1;
                } else {
                    e = mid-1;
                }
            } else {
                if(mid+1 < n && nums[mid] == nums[mid+1]) {
                    s = mid+2;
                } else {
                    e = mid;
                }
            }
        }

        return -1;
        */

        // XOR O(n)

        int ans = 0;

        for(int i : nums) {
            ans = ans^i;
        }

        return ans;
    }
}