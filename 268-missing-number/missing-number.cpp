class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n+1, -1);

        for (int i = 0; i<n; i++) {
            arr[nums[i]] = nums[i];
        }

        for (int i = 0; i<n+1; i++) {
            if (arr[i] != i) {
                return i;
            }
        }

        return -1;
    }
};