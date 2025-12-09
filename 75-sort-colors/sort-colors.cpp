class Solution {
private:
    void swap(vector<int>& nums, int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int mid = 0;
        int right = nums.size()-1;

        while (mid <= right) {
            if (nums[mid] == 0) {
                swap(nums, mid, left);
                left++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums, mid, right);
                right--;
            }
        }
    }
};