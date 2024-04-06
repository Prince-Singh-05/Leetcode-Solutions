class Solution {
public:

    int findDuplicate(vector<int>& nums) {

        // visited Solution -> modifies the array -> T.C = O(n) & S.C = O(1)
        // int ans = -1;

        // for(int i = 0; i<nums.size(); i++) {
        //     int index = abs(nums[i]);

        //     if(nums[index] < 0) {
        //         return index;
        //     }

        //     nums[index] *= -1;
        // }

        // return -1;

        // positioning Method -> modifies the array -> T.C = O(n) & S.C = O(1)

        while(nums[0] != nums[nums[0]]) {
            swap(nums[0], nums[nums[0]]);
        }
        return nums[0];
    }
};