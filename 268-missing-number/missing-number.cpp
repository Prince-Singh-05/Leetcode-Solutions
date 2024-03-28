class Solution {
public:

    int sortingMethod(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); i++) {
            if(nums[i] != i) {
                return i;
            }
        }

        return nums.size();
    }

    int missingNumber(vector<int>& nums) {

        // return sortingMethod(nums);

        // XOR Method
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            ans ^= nums[i];
        }

        for(int i = 0; i<=n; i++) {
            ans ^= i;
        }

        return ans;
    }
};