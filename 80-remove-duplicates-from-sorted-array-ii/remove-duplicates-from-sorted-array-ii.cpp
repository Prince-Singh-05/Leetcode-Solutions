class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 1;
        int threshold = 1;

        while (j < nums.size()) {
            if (nums[j] == nums[j-1] && threshold < 2) {
                nums[++i] = nums[j];
                threshold++;
            } else if (nums[j] != nums[j-1]) {
                nums[++i] = nums[j];
                threshold = 1;
            }

            j++;
        }

        return i+1;
    }
};