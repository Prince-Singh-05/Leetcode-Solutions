class Solution {
private:
    void swap(vector<int>& nums, int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

public:
    void nextPermutation(vector<int>& nums) {
        int idx = -1;
        int n = nums.size();

        // find the breakpoint index
        for (int i = n-2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) {
                idx = i;
                break;
            }
        }

        // EDGE CASE: current array is last permutation
        if (idx == -1) {
            int i = 0;
            int j = n-1;

            while (i <= j) {
                swap(nums, i, j);
                i++;
                j--;
            }

            return;
        }

        // swap the just larget number
        for (int i = n-1; i > idx; i--) {
            if (nums[i] > nums[idx]) {
                swap(nums, i, idx);
                break;
            }
        }

        // sort the second part of array
        sort(nums.begin()+idx+1, nums.end());
    }
};