class Solution {
    public int numIdenticalPairs(int[] nums) {
        int n = nums.length;
        
        // O(n^2)
        // int count = 0;

        // for(int i = 0; i<n-1; i++) {
        //     for(int j = i+1; j<n; j++) {
        //         if(nums[i] == nums[j]) {
        //             count++;
        //         }
        //     }
        // }

        // O(N)

        int ans = 0;
        int count[] = new int[101];

        for(int i : nums) {
            ans += count[i]++;
        }

        return ans;
    }
}