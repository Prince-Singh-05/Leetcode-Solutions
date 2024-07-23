class Solution {
public:

    // T.C => O(N) && S.C => O(1)
    // int findMin(vector<int>& nums) {
    //     int mini = nums[0];

    //     for(int i = 0; i<nums.size()-1; i++) {
    //         if(nums[i] > nums[i+1]) {
    //             mini = nums[i+1];
    //             break;
    //         }
    //     }

    //     return mini;
    // }

    // T.C => O(logN) && S.C => O(1)

    int findMin(vector<int>& nums) {
        int mini = INT_MAX;
        int n = nums.size();
        int l = 0, r = n-1;

        while(l <= r) {
            int mid = l + (r-l)/2;

            if(nums[mid] >= nums[l]) {
                mini = min(mini, nums[l]);
                l = mid+1;
            } else if(nums[mid] <= nums[r]) {
                mini = min(mini, nums[mid]);
                r = mid-1;
            }
        }

        return mini;

    }
};