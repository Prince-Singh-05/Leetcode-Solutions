class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        // Brute Force => T.C = O(N^2) && S.C = O(1)
        // int maxLen = 0;
        // int zeros = 0;

        // for(int i = 0; i<nums.size(); i++) {
        //     zeros = 0;

        //     for(int j = 0; j < nums.size(); j++) {
        //         if(nums[j] == 0) {
        //             zeros++;
        //         }

        //         if(zeros <= k) {
        //             int len = j - i + 1;
        //             maxLen = max(maxLen, len);
        //         } else {
        //             break;
        //         }

        //     }
        // }

        // return maxLen;

        // Better => T.C = O(2N) && S.C = O(1)
        // int maxLen = 0;
        // int l = 0, r = 0;
        // int zeros = 0;

        // while(r < nums.size()) {
        //     if(nums[r] == 0) {
        //         zeros++;
        //     }

        //     while(zeros > k) {
        //         if(nums[l] == 0) {
        //             zeros--;
        //         }
        //         l++;
        //     }

        //     if(zeros <= k) {
        //         maxLen = max(maxLen, r-l+1);
        //     }
        //     r++;
        // }

        // return maxLen;

        // Optimal => T.C = O(N) && S.C = O(1)
        int maxLen = 0;
        int l = 0, r = 0;
        int zeros = 0;

        while(r < nums.size()) {
            if(nums[r] == 0) {
                zeros++;
            }

            if(zeros > k) {
                if(nums[l] == 0) {
                    zeros--;
                }
                l++;
            } else {
                maxLen = max(maxLen, r-l+1);
            }

            r++;
        }

        return maxLen;
    }
};